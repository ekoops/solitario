#ifndef SOLITARIO_DECK_H
#define SOLITARIO_DECK_H


#include <array>
#include <random>
#include <functional>
#include <sstream>
#include <iostream>
#include <chrono>
#include "card.h"
#define DIM 40

class deck {
    std::array<card, DIM> cards_;
public:
    explicit deck();
    [[nodiscard]] std::array<card, DIM> const& get_cards() const;
    void shuffle();
    void print();
};


#endif //SOLITARIO_DECK_H
