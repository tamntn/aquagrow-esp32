void setup() {
  Serial.begin(115200);
  while (!Serial) {
  }
  Serial.println("Serial Communication Initialized");
  Serial2.begin(9600);                               //set baud rate for the software serial port to 9600
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
  pinMode(pH_Pump, OUTPUT);
  Serial.println("Now connecting to wifi");
  delay(4000);
  Serial.println("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(pH_Pump, channel);
  
}
