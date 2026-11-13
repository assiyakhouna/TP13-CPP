
#include <iostream>
#include "ArrayDyn.hpp"

int main() {

    // Creation d'un tableau dynamique
    ArrayDyn<int> tab(2);

    // Ajout des elements
    tab.push_back(10);
    tab.push_back(20);
    tab.push_back(30);
    tab.push_back(40);

    // Affichage
    std::cout << "=== Tableau initial ===" << std::endl;

    for (std::size_t i = 0; i < tab.size(); i++) {
        std::cout << tab[i] << std::endl;
    }

    // Affichage de la taille et capacite
    std::cout << "Taille : " << tab.size() << std::endl;
    std::cout << "Capacite : " << tab.capacity() << std::endl;

    // Suppression du dernier element
    tab.pop_back();

    std::cout << "\n=== Apres suppression ===" << std::endl;

    for (std::size_t i = 0; i < tab.size(); i++) {
        std::cout << tab[i] << std::endl;
    }

    // Constructeur de copie
    ArrayDyn<int> tab2(tab);

    std::cout << "\n=== Copie du tableau ===" << std::endl;

    for (std::size_t i = 0; i < tab2.size(); i++) {
        std::cout << tab2[i] << std::endl;
    }

    // Operateur d'affectation
    ArrayDyn<int> tab3;
    tab3 = tab;

    std::cout << "\n=== Affectation ===" << std::endl;

    for (std::size_t i = 0; i < tab3.size(); i++) {
        std::cout << tab3[i] << std::endl;
    }

    return 0;
}
