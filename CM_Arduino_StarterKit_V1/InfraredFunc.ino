

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

