#include <Arduino.h>
#include "button.h"

namespace 

// private variables
{
     const uint8_t BUTTON_PIN = 2;
    bool isPressed = false;
}

//public functions
    void Button::Initialize()
    {
        // I  Implementation for button initialization
        pinMode(BUTTON_PIN, INPUT_PULLUP);
    }

    void Button::Update()
    {
      // Implementation for button update
      isPressed = digitalRead(BUTTON_PIN) == LOW;
    }

    bool Button::IsPressed()
    {
        // Implementation for checking if button is pressed
        return isPressed;
    }

