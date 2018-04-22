/* failsafe funcion to revert every controls to a safe state 
 if the system is unable to get the commands from the server*/

void failSafe(){
  if (getErrorCount==0){

  }else if(getErrorCount==1){
    
  }else if(getErrorCount==2){
    Serial.println("Couldn't get command for two cycles so turning the water pump off");
    wPumpStatus = 0;
  }else if(getErrorCount==10){
    Serial.println("Couldn't get command for ten cycles so turning the light and heat off");
    lightStatus = 0;
    heatStatus = 0;
  }else if(getErrorCount==1){
    
  }else if(getErrorCount==1){
    
  }
  
}

