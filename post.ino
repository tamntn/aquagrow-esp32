void setPayload(){
  payload = "";
  payload+="{";
  payload += "\"airTemp\": \"" + (String)aTemp + "\" ,";
  payload += "\"airHumidity\": \"" + (String)hum + "\" ,";
  payload += "\"lightIntensity\":\"" + (String)lux +"\" ,";
  payload += "\"waterTemp\":\"" + (String)wTemp + "\" ,";
  payload += "\"upperWaterLevel\":\"" + (String)uWaterL + "\" ,";
  payload += "\"lowerWaterLevel\":\"" + (String)lWaterL+ "\" ,";
  payload += "\"pH\":\"" + (String)pH + "\"";
  payload+="}";
}

void postVal() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    HTTPClient httpP;
    Serial.println("Posting Value");
    httpP.begin(pUrl);
    httpP.addHeader("Content-Type", "application/json");
    int httpPResponseCode = httpP.POST(payload);

    if (httpPResponseCode > 0) {
      String response = httpP.getString();
      Serial.println(httpPResponseCode);
      Serial.println(response);
     
    } else {

      Serial.print("Error on sending POST: ");
      Serial.println(httpPResponseCode);
    }
    httpP.end();
  } else {
    Serial.println("Error in WiFi connection");
  }
}


