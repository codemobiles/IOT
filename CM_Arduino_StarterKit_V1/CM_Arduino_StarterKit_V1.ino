
#include <LiquidCrystal_I2C.h>
#define ANALOG_PIN A0       
#define IRsensor 2
LiquidCrystal_I2C lcd(0x27, 16, 2);


int analogValue = 0;        
int value = 0;
int counter = 0;
int last_count = 0;
volatile long lastStatusOccured = 0;
boolean found = false;

void setup(){
  
    initialization();
    initialDisplay();
    
}

void loop(){
  
    readAnalogValue();
    lcd.setCursor(12, 1);
    lcd.print(" ");
    lcd.setCursor(11, 1); 
    lcd.print(counter);
   
    Serial.print("Analog Value = ");       
    Serial.println(analogValue);
    Serial.print("CM_Counter: ");
    Serial.println(counter);             
 
    delay(100);                             
    value = analogValue;
    
}

void initialization(){
  
    Serial.begin(115200);      
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(IRsensor, INPUT_PULLUP); 
    attachInterrupt(digitalPinToInterrupt(IRsensor),interruptFunc,CHANGE);    
    
}

void initialDisplay(){
  
    lcd.init();        
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("CodeMobiles");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Ready");  
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("CM_Counter: ");
    Serial.println("www.arduino.codemobiles.com");  
    Serial.println("Infrared Counter Demo"); 
    
}

void readAnalogValue(){

  analogValue = analogRead(ANALOG_PIN);   
   if(analogValue>value+5 ){
        counter++;
   }else 
   if(analogValue<value-5){
        if(counter>0){
          counter--;
        }
   } 
  
}

void interruptFunc()
{  
  long fin = millis();
  if(fin - lastStatusOccured > 50)
  {  
    found = !found;
    if(found == true){
      counter++; 
  
      if (last_count != counter){
        Serial.print("CM_Counter: ");  
        Serial.println(counter);  
      }
      
      last_count = counter;
    }
  }
  lastStatusOccured = fin;
}
