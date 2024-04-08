/*
Auther: Sahil Mahendra Mangaonkar
Description: This program reads button state from ThingSPeak cloud and triggers the relay accordingly.
*/
// Home automation using Google assistant.

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//Pin declarations
#define LED D1

//Wi-Fi credentials
const char ssid[] = "Lenovo K8 Note 9382";  // network SSID
const char pass[] = "1234567890";           // network password

WiFiClient client;
int readValue;                              // variable to store channel field reading

unsigned long myChannelNumber = 1186960;        // ThingsSpeak Channel Number
const char* myReadAPIKey = "9DP5DMKJSM2LTMCZ";  // Channel Read API Key

void setup() {

  Serial.begin(115200);      // Set Baud rate for Serial communication
  WiFi.begin(ssid, pass);    // Set up Wi-Fi communication
  ThingSpeak.begin(client);  //Set up ThingSpeak client
  pinMode(LED, OUTPUT);      // Set D1 pin as output
  digitalWrite(LED, LOW);    // Set LED & Bulb to low value (Off by default)

}

void loop() {

  // Read the latest value from field 1 of your channel.
  readValue = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);

  if (readValue == 1) {
    digitalWrite(LED, HIGH);  //Relay's input pin will be set to high logic & the bilb will be turned on.
    Serial.println("Bulb is on");
  }

  else {
    digitalWrite(LED, LOW);  // Relay's input pin will be set to low logic & the bilb will be turned off.
    Serial.println("Bulb is off");
  }

}