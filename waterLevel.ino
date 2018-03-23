boolean hasWater;

boolean getLevel(int x){
  int temp = digitalRead(x);
  if(temp==1) {
    hasWater = true;
  }else hasWater = false;
  return hasWater;
}

