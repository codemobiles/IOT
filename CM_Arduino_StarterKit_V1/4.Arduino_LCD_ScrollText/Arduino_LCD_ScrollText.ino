#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup(){
   initialDisplay(); 
}
void loop(){
   scrollTextDisplay();
}
void initialDisplay(){
    lcd.init();        
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.setCursor(0, 0);
    lcd.print("CodeMobiles"); 
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Ready");  
    delay(2000);
} 
void scrollTextDisplay(){
  
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) { 
        lcd.scrollDisplayLeft(); 
        delay(200);
    }for (int positionCounter = 0; positionCounter < 29; positionCounter++) { 
        lcd.scrollDisplayRight(); 
        delay(200);
    } 
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) { 
        lcd.scrollDisplayLeft(); 
        delay(200);
    }
    delay(5000);
    
}
