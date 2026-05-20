#pragma once
#include <vector>
#include <string>

class BigNumber{
    public:
        BigNumber();
        BigNumber(const std::string& number, bool negative = false);
        std::string toString();

    private:
        std::vector<int> digits_;
        bool negative_;
};