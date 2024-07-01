#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include<ESP8266WebServer.h>
#include<ESP8266WiFi.h>
#include<DNSServer.h>
#include<Arduino.h>

// Replace with your network credentials
const char* ssid = "Airtel_BhandGogi";
const char* password = "admin@123";

// ThingSpeak settings
unsigned long myChannelNumber = 2589080;
const char* myWriteAPIKey = "D6651L0OQT3NG8XC";

WiFiClient client;
int pirPin = D5; // GPIO pin where the PIR sensor is connected
int pirState = LOW; // PIR state
int val = 0; // Variable to store the PIR sensor status

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(pirPin, INPUT); // Set PIR pin as input
  WiFi.begin(ssid, password); // Connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

  }
  Serial.println("WiFi connected");

  ThingSpeak.begin(client); // Initialize ThingSpeak
}

void loop() {
  val = digitalRead(pirPin); // Read the state of the PIR sensor

  if (val == HIGH) {
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
      ThingSpeak.writeField(myChannelNumber, 1, pirState, myWriteAPIKey); // Update ThingSpeak
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
      ThingSpeak.writeField(myChannelNumber, 1, pirState, myWriteAPIKey); // Update ThingSpeak
    }
  }
  delay(10000); // Wait for 10 seconds
}
