#include "ForceSensor.h"

namespace KneeTraction
{
    ForceSensor::ForceSensor(int dataPin, int clockPin)
    {
        loadCell.begin(dataPin, clockPin);

        calibrationFactor = 39570.88;
    }

    void ForceSensor::begin()
    {
        loadCell.set_scale(calibrationFactor);
    }

    void ForceSensor::tare()
    {
        loadCell.tare();
    }

    float ForceSensor::getForce()
    {
        return loadCell.get_units(10);
    }
}