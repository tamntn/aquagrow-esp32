#include <HTTPClient.h>
#include <WiFi.h>
#include "DHT.h"

// Uncomment one of the lines below for whatever DHT sensor type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Replace with your network credentials
const char* ssid     = "Thunderdome 2.0";
//const char* password = "guitar54";
String payload;

WiFiServer server(80);


const int DHTPin = 26;

DHT dht(DHTPin, DHTTYPE);


static char celsiusTemp[7];
static char fahrenheitTemp[7];
static char humidityTemp[7];

// Client variables 
char linebuf[80];
int charcount=0;

void setup() {
  dht.begin();
  
  Serial.begin(115200);
  while(!Serial) {
  }
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin("Thunderdome 2.0","guitar54" );
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    HTTPClient http;
    http.begin("https://api-test-sensor.herokuapp.com/api/sensors");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "application/json");             //Specify content-type header
     Serial.println("new client");
    memset(linebuf,0,sizeof(linebuf));
    charcount=0;
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        linebuf[charcount]=c;
        if (charcount<sizeof(linebuf)-1) charcount++;
        if (c == '\n' && currentLineIsBlank) {
            float h = dht.readHumidity();
            float t = dht.readTemperature();
            // Read temperature as Fahrenheit (isFahrenheit = true)
            float f = dht.readTemperature(true);
            // Check if any reads failed and exit early (to try again).
            if (isnan(h) || isnan(t) || isnan(f)) {
              Serial.println("Failed to read from DHT sensor!");
              strcpy(celsiusTemp,"Failed");
              strcpy(fahrenheitTemp, "Failed");
              strcpy(humidityTemp, "Failed");         
            }
            else{
              // Computes temperature values in Celsius + Fahrenheit and Humidity
              float hic = dht.computeHeatIndex(t, h, false);       
              dtostrf(hic, 6, 2, celsiusTemp);             
              float hif = dht.computeHeatIndex(f, h);
              dtostrf(hif, 6, 2, fahrenheitTemp);         
              dtostrf(h, 6, 2, humidityTemp);
              // You can delete the following Serial.print's, it's just for debugging purposes
              Serial.print("Humidity: ");
              Serial.print(h);
              Serial.print(" %\t Temperature: ");
              Serial.print(t);
              Serial.print(" *C ");
              Serial.print(f);
              Serial.print(" *F\t Heat index: ");
              Serial.print(hic);
              Serial.print(" *C ");
              Serial.print(hif);
              Serial.print(" *F");
              Serial.print("Humidity: ");
              Serial.print(h);
              Serial.print(" %\t Temperature: ");
              Serial.print(t);
              Serial.print(" *C ");
              Serial.print(f);
              Serial.print(" *F\t Heat index: ");
              Serial.print(hic);
              Serial.print(" *C ");
              Serial.print(hic);
              Serial.println(" *F");
              payload += '{';
              payload+= "\"temp\": ";
              payload +=  String(hic) +" ,";
              payload += "\"humidity\": ";
              payload += String(h) + "}";
              Serial.println(payload);
              int httpResponseCode = http.POST(payload);   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
          }
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println();
          client.println("<!DOCTYPE HTML><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<meta http-equiv=\"refresh\" content=\"30\"></head>");
          client.println("<body><div style=\"font-size: 3.5rem;\"><p>ESP32 - DHT</p><p>");
          if(atoi(celsiusTemp)>=25){
            client.println("<div style=\"color: #930000;\">");
          }
          else if(atoi(celsiusTemp)<25 && atoi(celsiusTemp)>=5){
            client.println("<div style=\"color: #006601;\">");
          }
          else if(atoi(celsiusTemp)<5){
            client.println("<div style=\"color: #009191;\">");
          }
          client.println(celsiusTemp);
          client.println("*C</p><p>");
          client.println(fahrenheitTemp);
          client.println("*F</p></div><p>");
          client.println(humidityTemp);
          client.println("%</p></div>");
          client.println("</body></html>");     
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
          memset(linebuf,0,sizeof(linebuf));
          charcount=0;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(2000);

    // close the connection:
    //client.stop();
    //Serial.println("client disconnected");
  }
}
void send(){
  
}


