
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

void setValueLCDAndSerialMonitor(){
  
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
void readAnalogVoltage(){
    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    voltage = sensorValue * (5.0 / 1023.0);
    // print out the value you read:
    Serial.println(voltage);
}

void setVoltageValue(){ 
    lcd.setCursor(9, 1);
    lcd.print(voltage);  
    delay(300);
}

void setTextVoltage(){
    lcd.setCursor(0, 0);
    lcd.print("CodeMobiles");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Voltage: ");  
    delay(2000);
}

