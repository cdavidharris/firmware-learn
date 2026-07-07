#pragma once

namespace PumpController
{
    enum class State
    {
        Idle,   // Ready, no pump demand
        Running, // Pump is operating
        Fault    // Pump is in fault state
    };
    void Initialize();
    void Update();
}