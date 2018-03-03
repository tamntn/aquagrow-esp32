void loop()
{
Serial.print("Posting to the api");
postVal();
delay(post_interval);  
payload = "";
}

