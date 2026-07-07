#include <Arduino.h>
#include "led.h"

namespace 
{
    const uint8_t LED_PIN = LED_BUILTIN;
    const unsigned long HEARTBEAT_INTERVAL_MS = 500;

    bool ledIsOn = false;
    unsigned long previousToggleTime = 0;
}

void Led::Initialize()
{
    pinMode(LED_PIN, OUTPUT);
    Off();
}

void Led::On()
{
    ledIsOn = true;
    digitalWrite(LED_PIN, HIGH);
}

void Led::Off()
{
    ledIsOn = false;
    digitalWrite(LED_PIN, LOW);
}

void Led::Toggle()
{
    if (ledIsOn)
    {
        Off();
    }
    else
    {
        On();
    }
}

void Led::Update()
{
    unsigned long currentTime = millis();

    if (currentTime - previousToggleTime >= HEARTBEAT_INTERVAL_MS)
    {
        previousToggleTime = currentTime;
        Toggle();       
    }
}

