
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
int thisChar = 'a'; 
float voltage = 0; 

void setup(){  
    initialization(); // 3, 4, 5
    initialDisplay();  // 1, 2, 3, 4,  
    setTextDisplay(); //4
    setCounterDisplay(); //4
}

void loop(){
    //เรียกใช้คำสั่งเขียนตัวอักษร
    //textDirection();//1
    //เรียกใช้คำสั่งเลื่อนข้อความซ้ายไปขวา, ขวาไปซ้าย
    //scrollTextDisplay();// 2
    //readAnalogVoltage(); // 3
    readAnalogValue(); // 4
    setValueLCDAndSerialMonitor(); // 4
    //setVoltageValue();// 3
    //serialPrint();// 5
}

void initialization(){
    Serial.begin(115200);      
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(IRsensor, INPUT_PULLUP); 
    attachInterrupt(digitalPinToInterrupt(IRsensor),interruptFunc,CHANGE);     
} 

