String payload = "";
///////////////Dht11////////////////////
#include "DHT.h"
#include "config.h"

DHT dht(DHTPin, DHTTYPE);
static char celsiusTemp[7];
static char fahrenheitTemp[7];
static char humidityTemp[7];







////////////Functions/////////////////
  ////////////Dht22///////
float getHIC();
float getHIF();
float getH();
