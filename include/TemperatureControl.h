#pragma once
#include "..\include\TemperatureRegulationInterface.h"

class TemperatureControl
{
private:
    const TemperatureRegulationInterface& temperatureRegulationInterface;
    float minTemp;
    float maxTemp;
public:

    TemperatureControl(const TemperatureRegulationInterface& temperatureRegulationInterface, float minTemp, float maxTemp)
		: temperatureRegulationInterface(temperatureRegulationInterface), minTemp(minTemp), maxTemp(maxTemp)
	{
	}
    TemperatureControl(float minTemp, float maxTemp)
    {
        this->minTemp = minTemp;
        this->maxTemp = maxTemp;
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
