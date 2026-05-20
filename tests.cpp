#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int passed = 0;
int total = 0;

void testToString(){
    BigNumber a("12345");
    bool ok = (a.toString() == "12345");
    total++;
    if(ok){ passed++; std::cout << "testToString passed" << std::endl;}
    else{ std::cout << "testToString FAILED" << std::endl;}
}

void testToStringNegative(){
    BigNumber a("12345", true);
    bool ok = (a.toString() == "-12345");
    total++;
    if(ok){ passed++; std::cout << "testToStringNegative passed" << std::endl;}
    else{ std::cout << "testToStringNegative FAILED" << std::endl;}
}

void testAddPositive(){
    BigNumber a("123");
    BigNumber b("456");
    bool ok = ((a + b).toString() == "579");
    total++;
    if(ok){ passed++; std::cout << "testAddPositive passed" << std::endl;}
    else{ std::cout << "testAddPositive FAILED" << std::endl;}
}

void testAddWithCarry(){
    BigNumber a("999");
    BigNumber b("1");
    bool ok = ((a + b).toString() == "1000");
    total++;
    if(ok){ passed++; std::cout << "testAddWithCarry passed" << std::endl;}
    else{ std::cout << "testAddWithCarry FAILED" << std::endl;}
}

void testAddNegative(){
    BigNumber a("50", true);
    BigNumber b("30", true);
    bool ok = ((a + b).toString() == "-80");
    total++;
    if(ok){ passed++; std::cout << "testAddNegative passed" << std::endl;}
    else{ std::cout << "testAddNegative FAILED" << std::endl;}
}

void testAddMixed(){
    BigNumber a("100");
    BigNumber b("40", true);
    bool ok = ((a + b).toString() == "60");
    total++;
    if(ok){ passed++; std::cout << "testAddMixed passed" << std::endl;}
    else{ std::cout << "testAddMixed FAILED" << std::endl;}
}

void testAddMixedNegativeBigger(){
    BigNumber a("30");
    BigNumber b("50", true);
    bool ok = ((a + b).toString() == "-20");
    total++;
    if(ok){ passed++; std::cout << "testAddMixedNegativeBigger passed" << std::endl;}
    else{ std::cout << "testAddMixedNegativeBigger FAILED" << std::endl;}
}

void testFirstTen(){
    BigNumber a("12345678901234");
    bool ok = (a.firstTen() == "1234567890");
    total++;
    if(ok){ passed++; std::cout << "testFirstTen passed" << std::endl;}
    else{ std::cout << "testFirstTen FAILED" << std::endl;}
}

void testFirstTenShort(){
    BigNumber a("12345");
    bool ok = (a.firstTen() == "12345");
    total++;
    if(ok){ passed++; std::cout << "testFirstTenShort passed" << std::endl;}
    else{ std::cout << "testFirstTenShort FAILED" << std::endl;}
}

void testGenerator(){
    NumberGenerator gen;
    bool ok = true;
    for(int i = 1; i <= 10; i++){
        BigNumber num = gen.generate(i);
        std::string str = num.toString();
        if(str[0] == '-') str = str.substr(1);
        if((int)str.size() != i){ok = false;}
    }
    total++;
    if(ok){ passed++; std::cout << "testGenerator passed" << std::endl;}
    else{ std::cout << "testGenerator FAILED" << std::endl;}
}

int main(){
    testToString();
    testToStringNegative();
    testAddPositive();
    testAddWithCarry();
    testAddNegative();
    testAddMixed();
    testAddMixedNegativeBigger();
    testFirstTen();
    testFirstTenShort();
    testGenerator();
    std::cout << "\nResult: " << passed << "/" << total << " passed tests" << std::endl;
    return 0;
}