void setup() {
  Serial.begin(115200);
  while(!Serial) {
  }
  Serial.println("Serial Communication Initialized");
  Serial.println("Initializing Ambient temperature sensor\t");
  dht.begin();
  Serial.print("Done");
  delay(50);
  Serial.println("Initializing wire communication\t");
  Wire.begin();
  Serial.println("Done");
  delay(50);
  Serial.println("Initializing Ambient light sensor\t");
  lightMeter.begin();
  Serial.println("Done");
  delay(50);
Serial.println("Now connecting to wifi");
delay(4000);
Serial.println("Connecting");
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
}
