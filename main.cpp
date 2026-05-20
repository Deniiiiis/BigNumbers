#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int main() {
    NumberGenerator gen;
    
    BigNumber a = gen.generate(5);
    std::cout << a.toString() << std::endl;
    
    BigNumber b = gen.generate(3);
    std::cout << b.toString() << std::endl;
    
    return 0;
}