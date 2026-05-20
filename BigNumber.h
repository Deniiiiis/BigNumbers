#pragma once
#include <vector>
#include <string>

class BigNumber{
    public:
        BigNumber();
        std::string toString();

    private:
        std::vector<int> digits_;
        bool negative_;
};