#include <Arduino.h>
#include "MotorController.h"
#include "ForceSensor.h"

// Motor pins
const int STEP_PIN = 18;
const int DIR_PIN  = 19;
const int EN_PIN   = 21;

// HX711 pins
const int HX711_DOUT_PIN = 13;
const int HX711_SCK_PIN  = 12;

// Create hardware objects
KneeTraction::MotorController motor(STEP_PIN, DIR_PIN, EN_PIN);
KneeTraction::ForceSensor forceSensor(HX711_DOUT_PIN, HX711_SCK_PIN);

bool movingForward = true;

unsigned long lastPrintTime = 0;
const unsigned long PRINT_INTERVAL = 200;

void setup()
{
    Serial.begin(115200);

    forceSensor.begin();

    Serial.println("Force sensor starting...");

    forceSensor.tare();

    Serial.println("Tare complete.");

    motor.moveForward();
}

void loop()
{
    // Keep the motor running continuously
    motor.run();

    // Update the force sensor whenever a new reading is available
    forceSensor.update();

    // Only print the force every 200 ms
    if (millis() - lastPrintTime >= PRINT_INTERVAL)
    {
        lastPrintTime = millis();

        Serial.println(forceSensor.getForce(), 2);
    }

    // Reverse direction when the motor reaches its target
    if (motor.distanceToGo() == 0)
    {
        delay(500);

        if (movingForward)
        {
            motor.moveTo(0);
        }
        else
        {
            motor.moveTo(1000);
        }

        movingForward = !movingForward;
    }
}