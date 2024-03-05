#pragma once
#include "TemperatureRegulationInterface.h"

template <typename TemperatureRegulationInterfaceT = TemperatureRegulationInterface>
class TemperatureControl
{
private:
    TemperatureRegulationInterfaceT& temperatureRegulationInterface;
    float minTemp;
    float maxTemp;
public:


    TemperatureControl(TemperatureRegulationInterfaceT& temperatureRegulationInterface, float minTemp, float maxTemp)
		: temperatureRegulationInterface(temperatureRegulationInterface), minTemp(minTemp), maxTemp(maxTemp)
	{
	}

    void regulateTemperature(float currentTemp)
    {
        if (currentTemp <= minTemp)
        {
			temperatureRegulationInterface.turnOnHeating();
		}
        else if (currentTemp >= maxTemp)
        {
			temperatureRegulationInterface.turnOnCooling();
		}
        else
        {
			temperatureRegulationInterface.turnOff();
		}
	}


    float getMinTemp() const
    {
        return minTemp;
    }

    void setMinTemp(float minTemp)
    {
        this->minTemp = minTemp;
    }

    float getMaxTemp() const
    {
        return maxTemp;
    }

    void setMaxTemp(float maxTemp)
    {
        this->maxTemp = maxTemp;
    }
};
