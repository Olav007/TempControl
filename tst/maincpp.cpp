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

TEST(TemperatureControl, testRegulateTemperatureCooling)
{
    TemperatureRegulationMock mocc;

    EXPECT_CALL(mocc, turnOnCooling());;
    TemperatureControl<> tc(&mocc, 18, 22);
    tc.regulateTemperature(23);
}

TEST(TemperatureControl, testRegulateTemperatureHeatAndSharedPointer)
{
    auto moccPtr = std::make_shared<TemperatureRegulationMock>();
    EXPECT_CALL(*moccPtr, turnOnHeating());
    TemperatureControl<decltype(moccPtr)> tc(moccPtr, 18, 22);
    tc.regulateTemperature(17);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv); // Initialize Google Mock (not always necessary, but included for completeness)
    return RUN_ALL_TESTS();
}