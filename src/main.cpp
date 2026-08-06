#include <Arduino.h>
#include <AccelStepper.h>

// Pin definitions
const int STEP_PIN = 18;
const int DIR_PIN  = 19;
const int EN_PIN   = 21;

// Create the stepper object
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

bool movingForward = true;

void setup()
{
    Serial.begin(115200);

    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, LOW);   // Enable TMC2209

    stepper.setMaxSpeed(1000);
    stepper.setAcceleration(500);

    stepper.moveTo(1000);
}

void loop()
{
    stepper.run();

    if (stepper.distanceToGo() == 0)
    {
        delay(500);

        if (movingForward)
        {
            stepper.moveTo(0);
        }
        else
        {
            stepper.moveTo(1000);
        }

        movingForward = !movingForward;
    }
}