#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "Garage Hotspot";  // Enter SSID here
const char* password = "StormyJackson";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", handle_OnConnect);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void handle_OnConnect() {
  Serial.println("GPIO7 Status: OFF | GPIO6 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status)); 
}