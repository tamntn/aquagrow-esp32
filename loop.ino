void loop()
{
////////////////////Sending commands to pH sensor//////////////  
 if (input_string_complete) {                        //if a string from the PC has been received in its entirety
    Serial2.print(inputstring); //send that string to the Atlas Scientific product
    Serial2.print('\r');                             //add a <CR> to the end of the string
    Serial.print("sent" + inputstring+"\n");
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }
//////////////////////////////////////////////////////////////////    
Serial.print("Posting to the api");
postVal();
delay(post_interval);  
payload = "";
}
