
void initialDisplay(){
    lcd.init();        
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void setTextDisplay(){
    lcd.setCursor(0, 0);
    lcd.print("CodeMobiles");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Ready");  
    delay(2000);
}

void setCounterDisplay(){
    lcd.setCursor(0, 1);
    lcd.print("CM_Counter: ");
    Serial.println("www.arduino.codemobiles.com");  
    Serial.println("Infrared Counter Demo"); 
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

