void getPh(){
   while (Serial2.available() > 0) {                   
    char inchar = (char)Serial2.read();              
    sensorstring += inchar;
    if (inchar == '\r') {
      sensor_stringcomplete = true;                   
    }
  }


  if (sensor_stringcomplete) {                       
   // Serial.println(sensorstring);                    
    pH = sensorstring.toFloat();                      

    sensorstring = "";                               
    sensor_stringcomplete = false;                    
    }
}
