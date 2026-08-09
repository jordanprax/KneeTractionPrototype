#ifndef FORCE_SENSOR_H
#define FORCE_SENSOR_H

#include <HX711.h>

namespace KneeTraction
{
    class ForceSensor
    {
    public:
        ForceSensor(int dataPin, int clockPin);

        void begin();
        void tare();
        void update();
        float getForce();

    private:
        HX711 loadCell;

        float calibrationFactor;
        float currentForce;
    };
}

#endif