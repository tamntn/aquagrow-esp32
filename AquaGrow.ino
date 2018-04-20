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


float lux, wTemp, aTemp, hum, pH;
String uWaterL = "false";
String lWaterL = "false";
String payload;
int freq = 5000;
int ledChannel = 0;
int resolution = 8;

//////////////////////////////////////////////////
String command="";
String wPumpStatus = "false";
String lightStatus = "false";
String heatStatus = "false";
String hPumpStatus = "false";
String ohPumpStatus = "false";
String wPumpInt = "0";
String lightInt = "0";
////////////////////////////////////////////////
