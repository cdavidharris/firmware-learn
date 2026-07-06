#include <Arduino.h>
#include <led.h>

namespace
{
    const uint8_t LED_PIN = LED_BUILTIN;
   bool ledIsOn = false;
}

void LedInitialize()
{ 
    const uint8_t LED_PIN = LED_BUILTIN;
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
    if (ledIsOn) {
        LedOff();
    } else {
        LedOn();
    }
}
