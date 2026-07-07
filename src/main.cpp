#include <Arduino.h>
#include "led.h"
#include "button.h"

void setup()
{
    Serial.begin(115200);

    Led::Initialize();
    Button::Initialize();

    Serial.println("Firmware Learn");
    Serial.println("Non-blocking hearbeat LED");

}

void loop()
{
    Button::Update();
    Led::Update();

    if (Button::IsPressed())
    {
        Led::On();
    }   
}
