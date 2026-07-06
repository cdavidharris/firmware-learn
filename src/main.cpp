#include <Arduino.h>
#include <led.h>

void setup()
{
   Serial.begin(115200);
   
   LedInitialize();

   Serial.println("Firmware Learn");
   Serial.println("LED module refactor");
}

void loop()
{
    LedToggle();
    delay(500);
}
