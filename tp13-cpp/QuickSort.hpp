
#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <concepts>

// Concept Sortable
template <typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

#endif
