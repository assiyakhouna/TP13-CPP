
#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T, int N, int M>
class Matrice {

private:
    T data[N][M];

public:

    // Constructeur par defaut
    Matrice() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = T{};
            }
        }
    }

    // Constructeur avec liste d'initialisation
    Matrice(std::initializer_list<T> valeurs) {

        if (valeurs.size() != N * M) {
            throw std::invalid_argument(
                "Nombre d'elements incorrect !"
            );
        }

        auto it = valeurs.begin();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = *it;
                ++it;
            }
        }
    }

    // Operateur +
    Matrice operator+(const Matrice& autre) const {

        Matrice resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat.data[i][j] =
                    data[i][j] + autre.data[i][j];
            }
        }

        return resultat;
    }

    // Operateur -
    Matrice operator-(const Matrice& autre) const {

        Matrice resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat.data[i][j] =
                    data[i][j] - autre.data[i][j];
            }
        }

        return resultat;
    }

    // Operateur * (multiplication matricielle)
    template <int P>
    Matrice<T, N, P> operator*(
        const Matrice<T, M, P>& autre
    ) const {

        Matrice<T, N, P> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {

                resultat.data[i][j] = T{};

                for (int k = 0; k < M; k++) {
                    resultat.data[i][j] +=
                        data[i][k] * autre.data[k][j];
                }
            }
        }

        return resultat;
    }

    // Operateur << pour afficher la matrice
    template <typename U, int L, int C>
    friend std::ostream& operator<<(
        std::ostream& os,
        const Matrice<U, L, C>& mat
    );

};

// Definition de l'operateur <<
template <typename T, int N, int M>
std::ostream& operator<<(
    std::ostream& os,
    const Matrice<T, N, M>& mat
) {

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < M; j++) {
            os << mat.data[i][j] << "\t";
        }

        os << std::endl;
    }

    return os;
}

#endif
