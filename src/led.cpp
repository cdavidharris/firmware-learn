#include <Arduino.h>
#include "led.h"

namespace
{
    const uint8_t LED_PIN = LED_BUILTIN;
    const unsigned long HEARTBEAT_INTERVAL_MS = 500;

    bool ledIsOn = false;
    unsigned long previousToggleTime = 0;
}

void LedInitialize()
{
    pinMode(LED_PIN, OUTPUT);
    LedOff();
}

void LedOn()
{
    ledIsOn = true;
    digitalWrite(LED_PIN, HIGH);
}

void LedOff()
{
    ledIsOn = false;
    digitalWrite(LED_PIN, LOW);
}

void LedToggle()
{
    if (ledIsOn)
    {
        LedOff();
    }
    else
    {
        LedOn();
    }
}

void LedUpdate()
{
    unsigned long currentTime = millis();
    if (currentTime - previousToggleTime >= HEARTBEAT_INTERVAL_MS)
    {
        previousToggleTime = currentTime;
        LedToggle();       
    }
}

