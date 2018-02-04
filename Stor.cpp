#include <iostream>
#include "utils/simple_string.h"

int main() {
    SimpleStr str = "Hello world";
    std::cout << str.toChar() << std::endl;
    return 0;
}
