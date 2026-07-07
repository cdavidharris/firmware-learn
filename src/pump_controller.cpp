#include "pump_controller.h"
#include "button.h"
#include "led.h"

namespace
{
    PumpController::State currentState = PumpController::State::Idle;
}

void PumpController::Initialize()
{
    // Implementation for pump controller initialization
    currentState=PumpController::State::Idle;    
}

void PumpController::Update()
{
    // Implementation for pump controller update
    if (Button::IsPressed())
    {
        currentState = PumpController::State::Running;
    }
    else
    {
        currentState = PumpController::State::Idle;
    }

    if (currentState == PumpController::State::Running)
    {
        Led::On();
    }
    else
    {
        Led::Off();
    }
}
