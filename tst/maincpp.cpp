#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TemperatureControl.h"

#include <iostream>

class TemperatureRegulation : public TemperatureRegulationInterface {
public:
    virtual void turnOnHeating(){}
	virtual void turnOnCooling() {};
	virtual void turnOff() {};
};

TEST(TemperatureControl, testRegulateTemperature)
{
	TemperatureRegulation reg;
	TemperatureControl tc(reg, 18, 22);
	tc.regulateTemperature(23);
}

int main()
{
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}