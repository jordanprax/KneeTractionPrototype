#include <Arduino.h>
#include "ForceSensor.h"

// HX711 pins
const int HX711_DOUT_PIN = 13;
const int HX711_SCK_PIN = 12;

// Create the force sensor object
KneeTraction::ForceSensor forceSensor(HX711_DOUT_PIN, HX711_SCK_PIN);

void setup()
{
    Serial.begin(115200);

    forceSensor.begin();

    Serial.println("Force sensor starting...");

    forceSensor.tare();

    Serial.println("Tare complete.");
}

void loop()
{
    float force = forceSensor.getForce();

    Serial.println(force, 2);

    delay(200);
}