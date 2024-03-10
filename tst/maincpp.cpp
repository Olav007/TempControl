#include "TemperatureControl.h" // Header here to make sure we have no dependence on libraries
#include <gtest/gtest.h>
#include <gmock/gmock.h>

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

TEST(TemperatureControl, test_Heating)
{
    TemperatureRegulationMock mocc;
    EXPECT_CALL(mocc, turnOnHeating());
    TemperatureControl<> tc(&mocc, 18, 22);
    tc.regulateTemperature(16);
}

TEST(TemperatureControl, test_Heat_and_Smart_pointer)
{
    auto moccPtr = std::make_shared<TemperatureRegulationMock>();
    EXPECT_CALL(*moccPtr, turnOnHeating());
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


TEST(TemperatureControl, test_Change_temperature_and_Cooling)
{
    TemperatureRegulationMock mocc;
    TemperatureControl<> tc(&mocc, 19.010203f, 21.21f);
    ASSERT_EQ(tc.getMinTemp(), 19.010203f);
    ASSERT_EQ(tc.getMaxTemp(), 21.21f);
    tc.setMinTemp(18.18f);
    tc.setMaxTemp(23.23f);
    EXPECT_CALL(mocc, turnOnCooling());
    tc.regulateTemperature(23.25);
    ASSERT_EQ(tc.getMinTemp(), 18.18f);
    ASSERT_EQ(tc.getMaxTemp(), 23.23f);
    bool exceptionThrown = false;
    try {
        tc.setMinTemp(24);
    }
    catch (...) { // Catches any exception
        exceptionThrown = true;
    }
    ASSERT_TRUE(exceptionThrown);
}


TEST(TemperatureControl, test_Heating_and_double)
{
    TemperatureRegulationMock mocc;
    TemperatureControl<TemperatureRegulationInterfaceP, double> tc(&mocc, 19.01, 21.21);
    ASSERT_EQ(tc.getMinTemp(), 19.01);
    ASSERT_EQ(tc.getMaxTemp(), 21.21);
    tc.setMinTemp(18.18);
    tc.setMaxTemp(23.23);
    EXPECT_CALL(mocc, turnOnHeating());
    tc.regulateTemperature(18);
    ASSERT_EQ(tc.getMinTemp(), 18.18);
    ASSERT_EQ(tc.getMaxTemp(), 23.23);
    bool exceptionThrown = false;
    try {
        tc.setMinTemp(24);
    }
    catch (...) { // Catches any exception
        exceptionThrown = true;
    }
    ASSERT_TRUE(exceptionThrown);
}

TEST(TemperatureControl, test_Heating_TurnOff_and_int)
{
	TemperatureRegulationMock mocc;
	TemperatureControl<TemperatureRegulationInterfaceP, int> tc(&mocc, 19.01f, 21.99f);
	ASSERT_EQ(tc.getMinTemp(), 19);
	ASSERT_EQ(tc.getMaxTemp(), 21);
	tc.setMinTemp(18.18f);
	tc.setMaxTemp(23.23f);
	EXPECT_CALL(mocc, turnOnHeating());
	tc.regulateTemperature(17);
    EXPECT_CALL(mocc, turnOff());
    tc.regulateTemperature(20);
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