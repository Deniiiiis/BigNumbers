#pragma once
#include <vector>
#include <string>

class BigNumber{
    public:
        // Constructor that creates a number with value 0
        BigNumber();

        // Create a BigNumber from a string, with an optional sign (default is positive)
        BigNumber(const std::string& number, bool negative = false);

        // Convert the BigNumber back to a string representation
        std::string toString() const;

        // Compare the absolute values of two BigNumbers
        BigNumber operator+(const BigNumber& other) const;

        // Get the first 10 digits of the number as a string
        std::string firstTen() const;

    private:
        // Store the digits in reverse order (least significant digit first)
        std::vector<int> digits_;

        // True if negative, false if positive
        bool negative_;

        // Adds digits of two numbers without considering their signs
        static BigNumber addAbsolute(const BigNumber& a, const BigNumber& b);

        // Returns 1 if |a| > |b|, -1 if |a| < |b|, and 0 if |a| == |b|
        static int compareValues(const BigNumber& a, const BigNumber& b);

        // Substract digits of two numbers, assumes |a| >= |b|
        static BigNumber subtractValues(const BigNumber& a, const BigNumber& b);
};