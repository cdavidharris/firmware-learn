#include <Arduino.h>

const uint8_t LED_PIN = LED_BUILTIN;
const unsigned long BLINK_INTERVAL_MS = 500;

bool ledIsOn = false;
unsigned long previousBlinkTime = 0;

void setup()
{
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(115200);

    Serial.println();
    Serial.println("Firmware Learn");
    Serial.println("Non-blocking blink started");
}

void loop()
{
    unsigned long currentTime = millis();

    if (currentTime - previousBlinkTime >= BLINK_INTERVAL_MS)
    {
        previousBlinkTime = currentTime;

        ledIsOn = !ledIsOn;

        digitalWrite(LED_PIN, ledIsOn);
        Serial.println(ledIsOn ? "LED ON" : "LED OFF");
    }
}