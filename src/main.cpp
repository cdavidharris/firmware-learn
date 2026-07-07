#include <Arduino.h>
#include "led.h"

void setup()
{
    Serial.begin(115200);

    Led::Initialize();
    
    Serial.println("Firmware Learn");
    Serial.println("Non-blocking hearbeat LED");

}

void loop()
{
    Led::Update();

}
