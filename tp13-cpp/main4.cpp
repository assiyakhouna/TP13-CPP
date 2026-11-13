
#include <iostream>
#include "QuickSort.hpp"

int main() {

    std::cout << std::boolalpha;

    std::cout << "int : "
              << Sortable<int> << std::endl;

    std::cout << "double : "
              << Sortable<double> << std::endl;

    std::cout << "string : "
              << Sortable<std::string> << std::endl;

    return 0;
}
