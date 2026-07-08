#include <Arduino.h>
#include "led.h"
#include "button.h"
#include "pump_controller.h"

void setup()
{
    Serial.begin(115200);

    Led::Initialize();
    Button::Initialize();

    Serial.println("Firmware Learn");
    Serial.println("Pump Controller module added");

}

void loop()
{
    Button::Update();
    PumpController::Update();
}