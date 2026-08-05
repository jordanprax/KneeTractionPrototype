#include <Arduino.h>

const int STEP_PIN = 18;
const int DIR_PIN  = 19;
const int EN_PIN   = 21;

void setup() {
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(EN_PIN, OUTPUT);

    digitalWrite(EN_PIN, LOW);
    digitalWrite(DIR_PIN, HIGH);
}

void loop() {

    for (int i = 0; i < 200; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(1000);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(1000);
    }

    delay(1000);

    digitalWrite(DIR_PIN, !digitalRead(DIR_PIN));

    delay(1000);
}