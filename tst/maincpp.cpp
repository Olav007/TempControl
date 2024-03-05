#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TemperatureControl.h"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

class TemperatureRegulationMock : public TemperatureRegulationInterface {
public:
    MOCK_METHOD(void, turnOnHeating, (), (override));
    MOCK_METHOD(void, turnOnCooling, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
};

TEST(TemperatureControl, testRegulateTemperature)
{
    TemperatureRegulationMock mocc;
    EXPECT_CALL(mocc, turnOnCooling());
    TemperatureControl<TemperatureRegulationMock> tc(mocc, 18, 22);
    tc.regulateTemperature(23);
}

TEST(TemperatureControl, testRegulateTemperatureHeat)
{
    TemperatureRegulationMock mocc;
    EXPECT_CALL(mocc, turnOnHeating());
    TemperatureControl<TemperatureRegulationMock> tc(mocc, 18, 22);
    tc.regulateTemperature(17);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv); // Initialize Google Mock (not always necessary, but included for completeness)
    return RUN_ALL_TESTS();
}