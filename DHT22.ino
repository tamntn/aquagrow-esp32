void getDHT(){
  delay(dht.getMinimumSamplingPeriod());
  aTemp = dht.getTemperature();
  hum = dht.getHumidity();
}
