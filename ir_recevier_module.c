/*
    Project name : ESP8266 IR Receiver Module
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-ir-receiver-module
*/

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t receiverPin = D2; // GPIO pin where the IR receiver OUT pin is connected

IRrecv irrecv(receiverPin); // Create an instance of IRrecv
decode_results results; // Variable to store the decoded IR results

void setup() {
  Serial.begin(9600); // Initialize serial communication
  irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the received IR code and its details
    Serial.print("Received IR Code: ");
    Serial.println(results.value, HEX);
    Serial.print("Bits: ");
    Serial.println(results.bits);
    Serial.print("Protocol: ");
    Serial.println(results.decode_type);
    Serial.println();

    irrecv.resume(); // Receive the next IR code
  }

  delay(100); // Add a small delay before the next reading
}
