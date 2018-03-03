void setup() {
  dht.begin();
  Wire.begin();
  lightMeter.begin();
  Serial.begin(115200);
  while(!Serial) {
  }
  
}
