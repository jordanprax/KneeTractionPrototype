#include <Arduino.h>
#include <HX711.h>

// HX711 pins
const int HX711_DOUT_PIN = 13;
const int HX711_SCK_PIN = 12;

// Create the HX711 object
HX711 loadCell;

void setup()
{
    Serial.begin(115200);

    loadCell.begin(HX711_DOUT_PIN, HX711_SCK_PIN);

    Serial.println("HX711 test starting...");

    loadCell.tare();

    Serial.println("Tare complete.");
}

void loop()
{
    if (loadCell.is_ready())
    {
        long reading = loadCell.read_average(10);

        Serial.println(reading);
    }
    else
    {
        Serial.println("HX711 not ready");
    }

    delay(200);
}