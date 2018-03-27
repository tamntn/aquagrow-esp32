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

    HTTPClient httpP;
    Serial.println("Posting Value");
    httpP.begin(pUrl);
    httpP.addHeader("Content-Type", "application/json");
    int httpPResponseCode = httpP.POST(getPayload());

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


