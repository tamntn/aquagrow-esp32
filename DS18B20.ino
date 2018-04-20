void getDS(void){
  sensors.requestTemperatures();
  wTemp = (sensors.getTempCByIndex(0));
}

