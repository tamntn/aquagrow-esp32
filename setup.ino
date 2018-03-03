void setup() {
  dht.begin();
  
  Serial.begin(115200);
  while(!Serial) {
  }
}
