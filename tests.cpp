#include <gtest/gtest.h>
#include "BigNumber.h"
#include "NumberGenerator.h"

// Tests that positive number converts to correct string
TEST(BigNumberTest, ToString){
    BigNumber a("12345");
    EXPECT_EQ(a.toString(), "12345");
}

// Tests that negative number has minus sign in string
TEST(BigNumberTest, ToStringNegative){
    BigNumber a("12345", true);
    EXPECT_EQ(a.toString(), "-12345");
}

// Tests basic addition of two positive numbers
TEST(BigNumberTest, AddPositive){
    BigNumber a("123");
    BigNumber b("456");
    EXPECT_EQ((a + b).toString(), "579");
}

// Tests addition where carry propagates e.g. 999 + 1 = 1000
TEST(BigNumberTest, AddWithCarry){
    BigNumber a("999");
    BigNumber b("1");
    EXPECT_EQ((a + b).toString(), "1000");
}

// Tests addition of two negative numbers
TEST(BigNumberTest, AddNegative){
    BigNumber a("50", true);
    BigNumber b("30", true);
    EXPECT_EQ((a + b).toString(), "-80");
}

// Tests addition where positive number is larger than negative
TEST(BigNumberTest, AddMixed){
    BigNumber a("100");
    BigNumber b("40", true);
    EXPECT_EQ((a + b).toString(), "60");
}

// Tests addition where negative number is larger than positive
TEST(BigNumberTest, AddMixedNegativeBigger){
    BigNumber a("30");
    BigNumber b("50", true);
    EXPECT_EQ((a + b).toString(), "-20");
}

// Tests that only first 10 digits are returned for long numbers
TEST(BigNumberTest, FirstTen){
    BigNumber a("12345678901234");
    EXPECT_EQ(a.firstTen(), "1234567890");
}

// Tests that short numbers are returned fully
TEST(BigNumberTest, FirstTenShort){
    BigNumber a("12345");
    EXPECT_EQ(a.firstTen(), "12345");
}

// Tests that generator produces numbers with correct digit count
TEST(NumberGeneratorTest, CorrectDigitCount){
    NumberGenerator gen;
    for(int i = 1; i <= 10; i++){
        BigNumber num = gen.generate(i);
        std::string str = num.toString();
        if(str[0] == '-') str = str.substr(1);
        EXPECT_EQ((int)str.size(), i);
    }
}