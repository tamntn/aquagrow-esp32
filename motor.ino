int freq = 2000;
int channelA = 0;
int channelB = 1;
int resolution = 8;
int startT=0;
void pHWriteA(int x,int t){
  startT=millis();
  while((millis()-startT)<t){
  ledcWrite(channelA, x);
  }
}
void pHWriteB(int x,int t){
  startT=millis();
  while((millis()-startT)<t){
  ledcWrite(channelB, x);
  }
}  
