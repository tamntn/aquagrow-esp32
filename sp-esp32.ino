String payload = "";
#include <Wire.h>
#include <WiFi.h>
#include <OneWire.h>
#include "config.h"
#include <HTTPClient.h>
#include <string.h>
///////////////Dht11////////////////////
#include "DHT.h"


DHT dht(DHTPin, DHTTYPE);
static char celsiusTemp[7];
static char fahrenheitTemp[7];
static char humidityTemp[7];
///////////////////////////////////////

/////////////DS18B20//////////////////
#include <DallasTemperature.h>;
OneWire DS18B20(TEMP_PIN);
DallasTemperature sensors(&DS18B20);

////////////BH1750///////////////////
#include <BH1750.h>
BH1750 lightMeter;

///////////pH///////////////////////
HardwareSerial Serial2(2);        //UART port for pH sensor
boolean input_string_complete = false;
String inputstring = "";                              
String sensorstring = "";                             
//inputstring.reserve(10);                            
//sensorstring.reserve(30);                           

////////////WIFI//////////////////





////////////Functions/////////////////
  ////////////Dht22///////
float getHIC();
float getHIF();
float getH();
  ////////////DS18B20////
float getTemp();
  ////////////BH1750//////
 int getLux();

 String getPayload();
 void postVal();
