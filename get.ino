String command="";
String wPumpStatus = "false";
String lightStatus = "false";
String heatStatus = "false";
String hPumpStatus = "false";
String ohPumpStatus = "false";
String wPumpInt = "0";
String lightInt = "0";

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
}

void parseC(){
  Serial.println("Parsing started");
  StaticJsonBuffer<300> JSONBuffer;
  JsonObject& parsed = JSONBuffer.parseObject(command);
  if (!parsed.success()) { 
    Serial.println("Parsing failed");
    delay(50);
    return;
  }
bool wPumpStatus = parsed["Data"]["waterPump"];
bool lightStatus = parsed["Data"]["growLight"];
bool heatStatus = parsed["Data"]["heatingMat"];
bool hPumpStatus = parsed["Data"]["HPump"];
bool ohPumpStatus = parsed["Data"]["OHPump"];
int wPumpInt = parsed["Data"]["waterPumpInt"];
int lightInt = parsed["Data"]["waterPumpInt"];
}

