#pragma once
#include <vector>
#include <string>

class BigNumber{
    public:
        BigNumber();
        BigNumber(const std::string& number, bool negative = false);
        std::string toString();
        BigNumber operator+(const BigNumber& other) const;

    private:
        std::vector<int> digits_;
        bool negative_;
        static BigNumber addAbsolute(const BigNumber& a, const BigNumber& b);
};