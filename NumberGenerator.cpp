#include "NumberGenerator.h"
#include <cstdlib>
#include <ctime>

NumberGenerator::NumberGenerator(){
    srand((unsigned int)time(nullptr));
}

std::string NumberGenerator::buildNumber(int digitLength){
    std::string result;
    result += ('1' + rand() % 9);
    for(int i = 1; i < digitLength; i++){
        result += ('0' + rand() % 10);
    }
    return result;
}

bool NumberGenerator::randomSign(){
    return rand() % 2 == 0;
}

BigNumber NumberGenerator::generate(int digitLength){
    return BigNumber(buildNumber(digitLength), randomSign());
}