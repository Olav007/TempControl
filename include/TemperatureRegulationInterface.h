#pragma once

class TemperatureRegulationInterface {
public:
    virtual void turnOnHeating() = 0;
    virtual void turnOnCooling() = 0;
    virtual void turnOff() = 0;
 };