#define ANALOG_PIN A0   

float voltage = 0;
void setup(){   
    Serial.begin(115200);
}

void loop(){  
    readAnalogVoltage();
}

void readAnalogVoltage(){
    int sensorValue = analogRead(ANALOG_PIN);
    voltage = sensorValue * (5.0 / 1023.0);
    // print out the value you read:
    Serial.print("CM_Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");
    delay(300);
} 
