 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);
int thisChar = 'a'; 

void setup() {
    // put your setup code here, to run once:
    initialDisplay();
}

void loop() {
    // put your main code here, to run repeatedly:
    textDirection();
}

void initialDisplay(){
    lcd.init();        
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void textDirection(){ 
  
    //เขียนย้อนกลับเมื่อ ค่ามีเท่ากับ 'm'
    if (thisChar == 'm') { 
        lcd.rightToLeft();
    } 
  
    //เขียนย้อนกลับเมื่อ ค่ามีเท่ากับ 's'
    if (thisChar == 's') { 
        lcd.leftToRight();
    }
    // reset at 'z':
    if (thisChar > 'z') { 
    //เริ่มต้นใหม่
        lcd.clear();
        lcd.home(); 
        thisChar = 'a';
    } 
    
    // เขียนตัวอักษร
    lcd.write(thisChar); 
    delay(1000); 
  
    //เพิ่มค่าตัวอักษร
    thisChar++;
    
}

