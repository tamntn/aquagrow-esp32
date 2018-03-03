float t;
float getTemp(){
  
  sensors.requestTemperatures();
  t= sensors.getTempCByIndex(0);
  while(t=-127.00){
  sensors.requestTemperatures();
  t= sensors.getTempCByIndex(0);
  Serial.println("got -127 error on DS12b20 :");
  }
  Serial.println(t);
  return t;
}

