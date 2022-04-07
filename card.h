#ifndef SOLITARIO_CARD_H
#define SOLITARIO_CARD_H

#include <exception>
#include <string>
#include <sstream>

enum seed_t {
    BASTONI, COPPE, SPADE, DENARI
};

class card {
    unsigned int value_;
    seed_t seed_;
    static std::string seed_to_str(seed_t s);
public:
    card();
    card(unsigned int v, seed_t s);
    bool value(unsigned int v);
    [[nodiscard]] unsigned int value() const;
    void seed(seed_t s);
    [[nodiscard]] seed_t seed() const;
    [[nodiscard]] std::string to_string() const;
    friend void swap(card &c1, card &c2);
};

#endif //SOLITARIO_CARD_H
