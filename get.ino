void getCom() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    HTTPClient httpG;
    Serial.println("Getting Commands");
    httpG.begin(gUrl);
    int httpGResponseCode = httpG.GET();
    if (httpGResponseCode > 0) {
      command = httpG.getString();
      Serial.println(httpGResponseCode);
    } else {

      Serial.print("Error on getting command");
      Serial.println(httpGResponseCode);
    }
    httpG.end();
  } else {
    Serial.println("Error in WiFi connection");
  }
  Serial.println(command);
}

void parseC(){
  Serial.println("Parsing started");
  StaticJsonBuffer<1500> JSONBuffer;
  JsonObject& parsed = JSONBuffer.parseObject(command);
  if (!parsed.success()) { 
    Serial.println("Parsing failed");
    delay(50);
    return;
  }else{
    Serial.println("Successfully Parsed");
  }
bool wPumpStatus = parsed["Data"]["waterPump"];
bool lightStatus = parsed["Data"]["growLight"];
bool heatStatus = parsed["Data"]["heatingMat"];
bool hPumpStatus = parsed["Data"]["phPumpLow"];
bool ohPumpStatus = parsed["Data"]["phPumpHigh"];
//int wPumpInt = parsed["Data"]["waterPumpInt"];
//int lightInt = parsed["Data"]["waterPumpInt"];
}
void printC(){
  Serial.println("Water Pump Status = " +  wPumpStatus);
 Serial.println("Grow Light Status = " + lightStatus);
 Serial.println("Heating mat Status = " + heatStatus );
 Serial.println("H+ Pump Status = " + hPumpStatus);
 Serial.println("OH- Pump Status = " + ohPumpStatus);
// Serial.println("Water Pump Speed = " + wPumpInt );
// Serial.println("Grow light internsity = " + lightInt );
}
