void loop(){
  setPump(100);
  getDHT();
  getDS();
  getBH();
  getLevel();
 // setPayload();
  //Serial.println(payload);
  //delay(5000);
  //postVal();
  
  //delay(5000);
  getCom();
  parseC();
  delay(5000);
 
}

