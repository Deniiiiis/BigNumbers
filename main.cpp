#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int main() {
BigNumber a("1");
BigNumber b("2");
std::cout << BigNumber::compareValues(a, b) << std::endl;

BigNumber c("1");
BigNumber d("1");
std::cout << BigNumber::compareValues(c, d) << std::endl;

BigNumber e("2");
BigNumber f("1");
std::cout << BigNumber::compareValues(e, f) << std::endl;
    
    return 0;
}