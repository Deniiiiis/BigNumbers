#pragma once
#include <string>
#include "BigNumber.h"

// Generates random BigNumbers with a specified number of digits
// First digit is always 1-9 to guarantee correct digit count
// Sign is randomly positive or negative
class NumberGenerator{
    public:
        // Initializes random generator with current time
        NumberGenerator();

        // Generates a random BigNumber with exactly digitLength digits
        BigNumber generate(int digitLength);

    private:
        // Builds digit string - first digit 1-9, remaining digits 0-9
        std::string buildNumber(int digitLength);

        // Returns true (negative) or false (positive) with 50/50 chance
        bool randomSign();
};