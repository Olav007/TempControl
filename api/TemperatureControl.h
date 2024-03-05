#pragma once
class TemperatureRegulationInterface {
public:
    virtual void turnOnHeating() = 0;//Torn on heating AND turn off cooling, if cooling is on
    virtual void turnOnCooling() = 0;//Torn on cooling AND turn off heating, if heating is on
    virtual void turnOff() = 0;//Urn of cooling and or heatiing, if on.
};
/* Note that this class doeesnt have to be used as a base class
   but the signature of the class should be used
*/
using TemperatureRegulationInterfaceP = TemperatureRegulationInterface*;

template <typename TemperatureRegulationInterfaceTP = TemperatureRegulationInterfaceP, typename TempNumber = float>
class TemperatureControl
{
private:
    TemperatureRegulationInterfaceTP const temperatureRegulationInterface;
    TempNumber minTemp;
    TempNumber maxTemp;
    static void validate(TempNumber min, TempNumber max)
    {
        if (min > max)
        {
			throw std::invalid_argument("minTemp must be less than maxTemp");
		}
	}
public:
    TemperatureControl(TemperatureRegulationInterfaceTP const temperatureRegulationInterface, TempNumber minTemp, TempNumber maxTemp)
		: temperatureRegulationInterface(temperatureRegulationInterface),  minTemp(minTemp), maxTemp(maxTemp)
	{
        validate(minTemp, maxTemp);
	}

    void regulateTemperature(TempNumber currentTemp)
    {
        if (currentTemp <= minTemp)
        {
			temperatureRegulationInterface->turnOnHeating();
		}
        else if (currentTemp >= maxTemp)
        {
			temperatureRegulationInterface->turnOnCooling();
		}
        else
        {
			temperatureRegulationInterface->turnOff();
		}
	}


    TempNumber getMinTemp() const
    {
        return minTemp;
    }

    void setMinTemp(TempNumber minTemp_p)
    {
        validate(minTemp_p, maxTemp);
        this->minTemp = minTemp_p;
    }

    TempNumber getMaxTemp() const
    {
        return maxTemp;
    }

    void setMaxTemp(TempNumber  maxTemp_p)
    {
        validate(minTemp, maxTemp_p);
        this->maxTemp = maxTemp_p;
    }
};
