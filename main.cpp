#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int main() {
    NumberGenerator gen;
    BigNumber sum;

    for(int i = 1; i <= 50; i++){
        BigNumber num = gen.generate(i);
        std::cout << "Number " << i << ".:" << num.toString() << std::endl;
        sum = sum+num;
    }

    std::cout << "First 10 digits of the sum: " << sum.firstTen() << std::endl;

    return 0;
}