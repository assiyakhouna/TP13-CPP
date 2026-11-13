
#ifndef ARRAYDYN_HPP
#define ARRAYDYN_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>
class ArrayDyn {

private:
    T* data;
    std::size_t taille;
    std::size_t capacite;

public:

    // Constructeur par defaut
    ArrayDyn() {
        data = nullptr;
        taille = 0;
        capacite = 0;
    }

    // Constructeur avec capacite initiale
    ArrayDyn(std::size_t cap) {
        taille = 0;
        capacite = cap;

        if (capacite > 0)
            data = new T[capacite];
        else
            data = nullptr;
    }

    // Constructeur de copie
    ArrayDyn(const ArrayDyn& autre) {

        taille = autre.taille;
        capacite = autre.capacite;

        if (capacite > 0) {
            data = new T[capacite];

            for (std::size_t i = 0; i < taille; i++) {
                data[i] = autre.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    // Operateur d'affectation
    ArrayDyn& operator=(const ArrayDyn& autre) {

        if (this != &autre) {

            T* nouveau = nullptr;

            if (autre.capacite > 0) {
                nouveau = new T[autre.capacite];

                for (std::size_t i = 0; i < autre.taille; i++) {
                    nouveau[i] = autre.data[i];
                }
            }

            delete[] data;

            data = nouveau;
            taille = autre.taille;
            capacite = autre.capacite;
        }

        return *this;
    }

    // Destructeur
    ~ArrayDyn() {
        delete[] data;
    }

    // Ajouter un element
    void push_back(const T& valeur) {

        if (taille == capacite) {

            std::size_t nouvelleCapacite =
                (capacite == 0) ? 1 : capacite * 2;

            T* nouveau = new T[nouvelleCapacite];

            for (std::size_t i = 0; i < taille; i++) {
                nouveau[i] = data[i];
            }

            delete[] data;

            data = nouveau;
            capacite = nouvelleCapacite;
        }

        data[taille] = valeur;
        taille++;
    }

    // Supprimer le dernier element
    void pop_back() {

        if (taille == 0) {
            throw std::out_of_range("Tableau vide !");
        }

        taille--;
    }

    // Acces aux elements avec controle de bornes
    T& operator[](std::size_t indice) {

        if (indice >= taille) {
            throw std::out_of_range("Indice invalide !");
        }

        return data[indice];
    }

    // Version constante de operator[]
    const T& operator[](std::size_t indice) const {

        if (indice >= taille) {
            throw std::out_of_range("Indice invalide !");
        }

        return data[indice];
    }

    // Obtenir la taille
    std::size_t size() const {
        return taille;
    }

    // Obtenir la capacite
    std::size_t capacity() const {
        return capacite;
    }

};

#endif
