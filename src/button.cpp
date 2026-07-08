#include <Arduino.h>
#include "button.h"

namespace 

// private variables
{
     const uint8_t BUTTON_PIN = 2;
     const unsigned long DEBOUNCE_TIME_MS = 50;


    bool isPressed = false;
    bool lastRawState = false;

    unsigned long lastChangeTime = 0;
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
      bool rawState = digitalRead(BUTTON_PIN) == LOW;
      unsigned long currentTime = millis();
     
    if (rawState != lastRawState)
    {
        lastChangeTime = currentTime;
        lastRawState = rawState;
    }

    if (currentTime - lastChangeTime >= DEBOUNCE_TIME_MS)
    {
        isPressed = rawState;
    }
}

    bool Button::IsPressed()
    {
        // Implementation for checking if button is pressed
        return isPressed;
    }

