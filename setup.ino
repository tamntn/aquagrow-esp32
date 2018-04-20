void setup(){
  dht.setup(dhtPin);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  sensors.begin();
  
Wire.begin();
lightMeter.begin();
delay(200);
Serial.println("Connecting to WiFi..");
WiFi.begin(ssid, password);
 
 while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    Serial.print(".");
    delay(500);
  }
pinMode(pH_Pump_A, OUTPUT);
pinMode(pH_Pump_B, OUTPUT);
pinMode(heatingMat, OUTPUT);
pinMode(light, OUTPUT);
pinMode(levelSensorB, INPUT);
pinMode(levelSensorG, INPUT);
digitalWrite(pump,HIGH);
ledcSetup(ledChannel, freq, resolution);
ledcAttachPin(pump, ledChannel);
setPump(255);
}

