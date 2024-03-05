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

TEST(TemperatureControl, test_Cooling)
{
    TemperatureRegulationMock mocc;
    EXPECT_CALL(mocc, turnOnCooling());;
    TemperatureControl<> tc(&mocc, 18, 22);
    tc.regulateTemperature(23);
}

TEST(TemperatureControl, test_Heat_and_Interface_template)
{
    auto moccPtr = std::make_shared<TemperatureRegulationMock>();
    TemperatureControl<decltype(moccPtr)> tc(moccPtr, 19, 21);
    tc.regulateTemperature(18);
}

TEST(TemperatureControl, test_Exception)
{
    TemperatureRegulationMock mocc;
    bool exceptionThrown = false;
    try {
        TemperatureControl<> tc(&mocc, 22, 19);
    }
    catch (...) { // Catches any exception
        exceptionThrown = true;
    }
    ASSERT_TRUE(exceptionThrown);

}


TEST(TemperatureControl, test_Change_temperature)
{
    TemperatureRegulationMock mocc;
    TemperatureControl<> tc(&mocc, 19, 21);
    ASSERT_EQ(tc.getMinTemp(), 19);
    ASSERT_EQ(tc.getMaxTemp(), 21);
    EXPECT_CALL(mocc, turnOnCooling());
    tc.regulateTemperature(22);
    tc.setMaxTemp(23);
    tc.setMinTemp(18);
    ASSERT_EQ(tc.getMinTemp(), 18);
    ASSERT_EQ(tc.getMaxTemp(), 23);
    bool exceptionThrown = false;
    try {
        tc.setMinTemp(24);
    }
    catch (...) { // Catches any exception
        exceptionThrown = true;
    }
    ASSERT_TRUE(exceptionThrown);

}




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv); // Initialize Google Mock (not always necessary, but included for completeness)
    return RUN_ALL_TESTS();
}