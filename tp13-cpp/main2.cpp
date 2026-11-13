#include <iostream>
#include "Matrice.hpp"

int main() {

    Matrice<int, 2, 2> A{1, 2, 3, 4};
    Matrice<int, 2, 2> B{5, 6, 7, 8};

    Matrice<int, 2, 2> C = A + B;
    Matrice<int, 2, 2> D = A - B;

    std::cout << "Addition testee !" << std::endl;
    std::cout << "Soustraction testee !" << std::endl;

    return 0;
}
