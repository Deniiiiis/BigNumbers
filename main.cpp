#include <iostream>
#include <string>
#include "BigNumber.h"
#include "NumberGenerator.h"

int main() {
    BigNumber a("2");
    BigNumber b("1");
    std::cout << (a + b).toString() << std::endl;

    BigNumber c("100");
    BigNumber d("50", true);
    std::cout << (c + d).toString() << std::endl;

    BigNumber e("4", true);
    BigNumber f("20", true);
    std::cout << (e + f).toString() << std::endl;

    BigNumber g("3");
    BigNumber h("120", true);
    std::cout << (g + h).toString() << std::endl;

    return 0;
}