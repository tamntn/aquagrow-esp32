int freq = 2000;
int channel = 0;
int resolution = 8;
int startT=0;
void pHWrite(int x,int t){
  startT=millis();
  while((millis()-startT)<t){
  ledcWrite(channel, x);
  }
}
  
