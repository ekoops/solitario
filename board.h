#ifndef SOLITARIO_BOARD_H
#define SOLITARIO_BOARD_H


#include <vector>
#include <sstream>
#include <iostream>
#include <list>
#include "card.h"

class board {
    std::vector<card> cards_;
public:
    void place(card const& c);
    void compact(bool has_to_print);
    [[nodiscard]] unsigned int length() const;
    void print();
};

#endif