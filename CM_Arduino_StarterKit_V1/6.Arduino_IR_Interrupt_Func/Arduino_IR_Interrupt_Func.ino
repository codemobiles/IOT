#define IRsensor 2 
int counter = 0;
int last_count = 0;
volatile long lastStatusOccured = 0;
boolean found = false;

void setup(){
    initialization();    
}

void loop(){  
}

void initialization(){
    Serial.begin(115200);      
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(IRsensor, INPUT_PULLUP); 
    attachInterrupt(digitalPinToInterrupt(IRsensor),interruptFunc,CHANGE);     
}

void interruptFunc(){  
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
