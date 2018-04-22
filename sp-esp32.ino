#include "DHTesp.h"
#include "config.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h>
#include <BH1750.h>

#include <WiFi.h>
#include <HTTPClient.h>

#include <ArduinoJson.h>


DHTesp dht;

BH1750 lightMeter;


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

HardwareSerial Serial2(2);    
float lux, wTemp, aTemp, hum;
float pH = 7;
//String pH ="";
String uWaterL = "false";
String lWaterL = "false";
String payload;
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
String sensorstring = "";                             
boolean sensor_stringcomplete = false;


int getErrorCount = 0;
//////////////////////////////////////////////////
String command="";
int wPumpStatus =0;
int lightStatus = 0;
int heatStatus = 0;
int hPumpStatus = 0;
int ohPumpStatus = 0;
String wPumpInt = "0";
String lightInt = "0";
////////////////////////////////////////////////
