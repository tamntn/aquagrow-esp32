
float h = dht.readHumidity();
float c = dht.readTemperature();
float f = dht.readTemperature(true);
float hf=0,cf=0,ff=0;


float getHIC(){
  if(isnan(c)){
    Serial.print("can't read *C");
  }else{
    cf = c;
  }
   // return cf;
   return 20;
}

 float getHIF(){
    if(isnan(f)){
    Serial.print("can't read *F");
  }else{
    ff = f;
  }
    return ff;
}
float getH(){
   if(isnan(h)){
    Serial.print("can't read Humidity");
  }else{
    hf = h;
  }
    //return hf;
    return 62;
}
