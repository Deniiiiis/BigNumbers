#pragma once
#include <string>
#include "BigNumber.h"

class NumberGenerator{
    public:
        NumberGenerator();
        BigNumber generate(int digitLength);

    private:
        std::string buildNumber(int digitLength);
        bool randomSign();
};