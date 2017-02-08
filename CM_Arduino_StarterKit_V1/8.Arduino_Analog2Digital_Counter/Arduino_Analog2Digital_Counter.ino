#define ANALOG_PIN A0   
int analogValue = 0;      
int value = 0;
int counter = 0;

void setup(){   
    Serial.begin(115200);
}

void loop(){  
    readAnalogValue();
}

void readAnalogValue(){ 
 //อ่านค่า Analog
    analogValue = analogRead(ANALOG_PIN);   
    if(analogValue>value+5 ){
        counter++;
    }else 
    if(analogValue<value-5){
        if(counter>0){
          counter--;
        }
    }         
    value = analogValue;
    Serial.print("CM_Couter: ");
    Serial.println(counter);
    delay(300);
}
