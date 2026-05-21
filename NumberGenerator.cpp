#include "NumberGenerator.h"
#include <cstdlib>
#include <ctime>

// time(nullptr) returns current time in seconds
// used as seed so random numbers differ on each program run
NumberGenerator::NumberGenerator(){
    srand((unsigned int)time(nullptr));
}

// First digit is 1-9 to guarantee correct digit count
// If first digit were 0, number would have fewer digits than expected
// Remaining digits are 0-9 for full randomness
std::string NumberGenerator::buildNumber(int digitLength){
    std::string result;
    result += ('1' + rand() % 9);
    for(int i = 1; i < digitLength; i++){
        result += ('0' + rand() % 10);
    }
    return result;
}

// rand() % 2 produces 0 or 1 with equal probability
// == 0 converts it to true/false for the negative parameter
bool NumberGenerator::randomSign(){
    return rand() % 2 == 0;
}

// Combines random digits and random sign into a single BigNumber
BigNumber NumberGenerator::generate(int digitLength){
    return BigNumber(buildNumber(digitLength), randomSign());
}