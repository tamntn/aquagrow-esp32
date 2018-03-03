String payload = "";
#include <Wire.h>
#include <OneWire.h>
///////////////Dht11////////////////////
#include "DHT.h"
#include "config.h"

DHT dht(DHTPin, DHTTYPE);
static char celsiusTemp[7];
static char fahrenheitTemp[7];
static char humidityTemp[7];
///////////////////////////////////////

/////////////DS18B20//////////////////
#include <DallasTemperature.h>;
OneWire DS18B20(TEMP_PIN);
DallasTemperature sensors(&DS18B20);








////////////Functions/////////////////
  ////////////Dht22///////
float getHIC();
float getHIF();
float getH();
  ////////////DS18B20////
float getTemp();
  /////////////////////
