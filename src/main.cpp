#include <Arduino.h>
#include "MotorController.h"

// Pin definitions
const int STEP_PIN = 18;
const int DIR_PIN  = 19;
const int EN_PIN   = 21;

// Create the stepper object
KneeTraction::MotorController motor(STEP_PIN, DIR_PIN, EN_PIN);

bool movingForward = true;

void setup()
{
    Serial.begin(115200);
    motor.moveForward();
}

void loop()
{
    motor.run();

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