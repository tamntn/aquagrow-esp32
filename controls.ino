

void setpHPumpA(boolean x) {
  if (x == 1) {
        Serial.println("PH B is high");
    ledcWrite(1, 255);
    delay(500);
            Serial.println("Setting it low");

    ledcWrite(1, 0);  }
}


void setpHPumpB(boolean x) {
  if (x == 1) {
    Serial.println("PH B is high");
    ledcWrite(2, 255);
    delay(500);
        Serial.println("Setting it low");

    ledcWrite(2, 0); ;
  }
}

void setPump(int x) {
  ledcWrite(ledChannel, x);
}

void setHeat(boolean x) {
  digitalWrite(heatingMat, x);
}

void setLight(boolean x) {
  digitalWrite(light, x);
}
