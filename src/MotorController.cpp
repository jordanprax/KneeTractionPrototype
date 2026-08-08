#include "MotorController.h"
#include <Arduino.h>

KneeTraction::MotorController::MotorController(int stepPin, int dirPin, int enPin)
    : stepper(AccelStepper::DRIVER, stepPin, dirPin),
      enPin(enPin)
{
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);

    stepper.setMaxSpeed(1000);
    stepper.setAcceleration(500);
}

void KneeTraction::MotorController::moveForward()
{
    stepper.moveTo(1000);
}

void KneeTraction::MotorController::run()
{
    stepper.run();
}

void KneeTraction::MotorController::stop()
{
    stepper.stop();
}

void KneeTraction::MotorController::moveTo(long position)
{
    stepper.moveTo(position);
}

long KneeTraction::MotorController::distanceToGo()
{
    return stepper.distanceToGo();
}