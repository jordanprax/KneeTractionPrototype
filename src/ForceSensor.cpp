#include "ForceSensor.h"

namespace KneeTraction
{
    ForceSensor::ForceSensor(int dataPin, int clockPin)
    {
        loadCell.begin(dataPin, clockPin);

        calibrationFactor = 39570.88;
        currentForce = 0.0;
    }

    void ForceSensor::begin()
    {
        loadCell.set_scale(calibrationFactor);
    }

    void ForceSensor::tare()
    {
        loadCell.tare();
        currentForce = 0.0;
    }

    void ForceSensor::update()
    {
        if (loadCell.is_ready())
        {
            currentForce = loadCell.get_units(1);
        }
    }

    float ForceSensor::getForce()
    {
        return currentForce;
    }
}