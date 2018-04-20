void getLevel(){
  int temp;
  temp = digitalRead(levelSensorB);
  if(temp == 1) {uWaterL = "true";
  }else uWaterL = "false";
  delay(50);
  temp = digitalRead(levelSensorG);
  if(temp == 1) {lWaterL = "true";
  }else lWaterL = "false";
  delay(50);
}
