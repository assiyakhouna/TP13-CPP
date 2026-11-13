
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstddef>

// Exception : pile pleine
class StackOverflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est pleine !";
    }
};

// Exception : pile vide
class StackUnderflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est vide !";
    }
};

#endif
