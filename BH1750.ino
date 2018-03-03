uint16_t lux;
int getLux(){
  lux = lightMeter.readLightLevel();
  //return lux;
  return 200;
}

