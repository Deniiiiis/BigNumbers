#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int main() {
    BigNumber a("123");
    BigNumber b("456");
    std::cout << (a + b).toString() << std::endl;
    
    BigNumber c("999");
    BigNumber d("1");
    std::cout << (c + d).toString() << std::endl;
    
    return 0;
}