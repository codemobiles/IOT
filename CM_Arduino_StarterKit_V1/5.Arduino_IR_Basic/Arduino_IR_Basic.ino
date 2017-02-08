int val = 0; 
int inputPin = 2;

void setup(){
    Serial.begin(115200);      
    pinMode(inputPin, INPUT); 
}

void loop(){ 
    val = digitalRead(inputPin);  //การค่า IR
    if (val == HIGH) {
        Serial.print("Codemobiles IR HIGH: ");
        Serial.println(val);
    }
    else{ 
        Serial.print("Codemobiles IR LOW: ");
        Serial.println(val);
    }
    delay(300);
}
