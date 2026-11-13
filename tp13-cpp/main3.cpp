
#include <iostream>
#include "Stack.hpp"

int main() {

    try {
        throw StackOverflow();
    }
    catch (const StackOverflow& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        throw StackUnderflow();
    }
    catch (const StackUnderflow& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
