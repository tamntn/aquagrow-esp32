String getPayload() {
payload+="{";
payload += "\"airTemp\": \"" + String(getHIC())+ "\",";
payload += "\"airHumidity\": \"" + String(getH())+ "\" ,";
payload += "\"lightIntensity\":\"" + String(getLux())+"\" ,";
payload += "\"waterTemp\":\"" + String(getTemp())+ "\"";
payload+="}";
Serial.println(payload);
return payload;
payload = "";
}

void postVal() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    HTTPClient http;
    Serial.println("Posting Value");
    http.begin("http://aquagrow.herokuapp.com/api/sensors");
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(getPayload());

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);

    } else {

      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Error in WiFi connection");
  }
}


