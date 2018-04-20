

void setpHPumpA(boolean x){
digitalWrite(pH_Pump_A,x);
}

void setpHPumpB(boolean x){
digitalWrite(pH_Pump_B,x);
}

void setPump(int x){
ledcWrite(ledChannel, x);
}

void setHeat(boolean x){
digitalWrite(heatingMat,x);
}

void setLight(boolean x){
digitalWrite(light,x);
}
