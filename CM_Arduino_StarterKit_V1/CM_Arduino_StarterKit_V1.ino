
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

void setup()
{
    Serial.begin(115200);      
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(IRsensor, INPUT_PULLUP); 
    attachInterrupt(digitalPinToInterrupt(IRsensor),interruptFunc,CHANGE);    
  
    lcd.init();        
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("CodeMobiles");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Ready"); 
    Serial.println("www.arduino.codemobiles.com");  
    Serial.println("Infrared Counter Demo"); 
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("CM_Counter: ");
}

void loop()
{
   analogValue = analogRead(ANALOG_PIN);   
   if(analogValue>value+5 ){
        counter++;
   }else 
   if(analogValue<value-5){
        if(counter>0){
          counter--;
        }
   } 
   lcd.setCursor(12, 1);
   lcd.print(" ");
   lcd.setCursor(11, 1); 
   lcd.print(counter);
   
  
  Serial.print("Analog input0 = ");       
  Serial.println(analogValue);
  Serial.print("CM_Counter: ");
  Serial.println(counter);             
 
  delay(100);                             
  value = analogValue;
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

