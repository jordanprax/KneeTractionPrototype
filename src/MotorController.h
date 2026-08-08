#include <AccelStepper.h>

namespace KneeTraction
{
    class MotorController
{
    public:
        MotorController(int stepPin, int dirPin, int enPin);
        void moveForward();
        void run();
        void stop();
        long distanceToGo();
        void moveTo(long position);
    
    private:
    AccelStepper stepper;
    int enPin;
};
}