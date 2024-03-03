#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TemperatureControl.h"

#include <iostream>

class TemperatureRegulationMock : public TemperatureRegulationInterface {
public:
    MOCK_METHOD(void, turnOnHeating, (), (override));
    MOCK_METHOD(void, turnOnCooling, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
};

TEST(TemperatureControl, testRegulateTemperature)
{
    TemperatureRegulationMock mocc;
    TemperatureControl tc(mocc, 18, 22);
    tc.regulateTemperature(23);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}