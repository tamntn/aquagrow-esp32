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
wPumpStatus = parsed["data"]["waterPump"];
lightStatus = parsed["data"]["growLight"];
heatStatus = parsed["data"]["heatingMat"];
ohPumpStatus = parsed["data"]["phPumpHigh"];
hPumpStatus = parsed["data"]["phPumpLow"];
//int wPumpInt = parsed["Data"]["waterPumpInt"];
//int lightInt = parsed["Data"]["waterPumpInt"];
delay(50);

}
void printC(){
  Serial.println("Water Pump Status = " +  (String)wPumpStatus);
 Serial.println("Grow Light Status = " + (String)lightStatus);
 Serial.println("Heating mat Status = " + (String)heatStatus );
 Serial.println("H+ Pump Status = " + (String)hPumpStatus);
 Serial.println("OH- Pump Status = " + (String)ohPumpStatus);
// Serial.println("Water Pump Speed = " + wPumpInt );
// Serial.println("Grow light internsity = " + lightInt );
}
