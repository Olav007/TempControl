#pragma once
// Create an interface for a class with void methods to turn on heating, turn on cooling
    class TemperatureRegulationInterface {
    public:
        virtual void turnOnHeating() = 0;
        virtual void turnOnCooling() = 0;
        virtual void turnOff() = 0;
    };
// and turn off heating and cooling.  The class should have	