

float pH;  //used to hold a floating point number that is the pH

void serialEvent() {                                  
  inputstring = Serial.readStringUntil(13);           
  input_string_complete = true;                       
}

float getPh(){
  if (Serial2.available() > 0) {                     
    char inchar = (char)Serial2.read();              
    sensorstring += inchar; 
                             
    if (inchar == '\r') {          
    pH =  sensorstring.toFloat();
    }
  
}
return pH;
}

