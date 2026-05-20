#include <iostream>
#include<string>
#include "BigNumber.h"

int main() {
    BigNumber a("12345");
    std::cout << a.toString() << std::endl;

    BigNumber b("12345", true);
    std::cout << b.toString() << std::endl;

    return 0;
}