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
unsigned long myChannelNumber = 2589118;
const char* myWriteAPIKey = "QOM8416ZP57D7XEW";
WiFiClient client;
int buttonPin = D1; // GPIO pin where the button is connected
int buttonState = HIGH; // Initial state of the button (not pressed)
int lastButtonState = HIGH; // Previous state of the button
unsigned long lastDebounceTime = 0; // Last time the button state was toggled
unsigned long debounceDelay = 50; // Debounce time in milliseconds

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  WiFi.begin(ssid, password); // Connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  ThingSpeak.begin(client); // Initialize ThingSpeak
}

void loop() {
  int reading = digitalRead(buttonPin); // Read the state of the button

  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset the debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading; // Update the button state

      if (buttonState == LOW) { // Button is pressed
        Serial.println("Button pressed!");
        ThingSpeak.writeField(myChannelNumber, 1, 1, myWriteAPIKey); // Update ThingSpeak
      } else { // Button is released
        Serial.println("Button released!");
        ThingSpeak.writeField(myChannelNumber, 1, 0, myWriteAPIKey); // Update ThingSpeak
      }
    }
  }

  lastButtonState = reading; // Save the reading
}
