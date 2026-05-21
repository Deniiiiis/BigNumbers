#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int main() {
    // Creates generator, seeds random with current time in constructor
    NumberGenerator gen;

    // Sum starts at 0, each number gets added to it
    BigNumber sum;

    // i-th number has exactly i digits
    for(int i = 1; i <= 50; i++){
        BigNumber num = gen.generate(i);
        std::cout << "Number " << i << ".:" << num.toString() << std::endl;
        // Accumulate sum after each generated number
        sum = sum+num;
    }

    // display only first 10 digits of the final sum
    std::cout << "First 10 digits of the sum: " << sum.firstTen() << std::endl;

    return 0;
}