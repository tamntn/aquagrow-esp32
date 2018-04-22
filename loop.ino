void loop() {
  // setPump(100);
  unsigned long time = millis();;
  getDHT();
  getDS();
  getBH();
  getLevel();
  getPh();
  sensorstring = "";
  setPayload();
  delay(100);
  Serial.println(payload);
  //delay(5000);
  time = millis();

  postVal();


  delay(100);
  getCom();
  delay(50);
  parseC();
  delay(50);
  //printC();
  //delay(5000);
  setPump(wPumpStatus);
  delay(50);
  setLight(lightStatus);
  delay(50);
  setHeat(heatStatus);
  delay(50);
  setpHPumpA(ohPumpStatus);
  delay(50);
  setpHPumpB(hPumpStatus);
  delay(50);
  Serial.println("The time taken by this loop is " + (String)(millis() - time));
}

