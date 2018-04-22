void setup(){
  Serial.println("Setting pH pump");
ledcSetup(1, freq, resolution);
ledcAttachPin(pH_Pump_A, 1);
setpHPumpA(0);
/////////////////////////
ledcSetup(2, freq, resolution);
ledcAttachPin(pH_Pump_B, 2);

setpHPumpB(0);  
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
    Serial2.begin(9600);                               //set baud rate for the software serial port to 9600
  delay(1000);
  //sensorstring.reserve(30);
digitalWrite(pH_Pump_A,LOW) ; 
digitalWrite( pH_Pump_B,LOW); 
//pinMode(pH_Pump_A, INPUT_PULLDOWN);
//pinMode(pH_Pump_B, INPUT_PULLDOWN);     
//pinMode(pH_Pump_A, OUTPUT);
//pinMode(pH_Pump_B, OUTPUT);
pinMode(heatingMat, OUTPUT);
pinMode(light, OUTPUT);
pinMode(levelSensorB, INPUT);
pinMode(levelSensorG, INPUT);
digitalWrite(pump,HIGH);
//digitalWrite(pH_Pump_A,LOW) ; 
//digitalWrite( pH_Pump_B,LOW); 
ledcSetup(ledChannel, freq, resolution);
ledcAttachPin(pump, ledChannel);
setPump(255);
////////////////////////////
Serial.println("Setting pH pump");
ledcSetup(1, freq, resolution);
ledcAttachPin(pH_Pump_A, 1);
setpHPumpA(0);
/////////////////////////
ledcSetup(2, freq, resolution);
ledcAttachPin(pH_Pump_B, 2);

setpHPumpB(0);
}

