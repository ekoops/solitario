#include "card.h"

std::string card::seed_to_str(seed_t s) {
    switch (s) {
        case BASTONI:
            return "BASTONI";
        case COPPE:
            return "COPPE";
        case SPADE:
            return "SPADE";
        case DENARI:
            return "DENARI";
    }
    return "";
}

card::card() : card{1, seed_t::BASTONI} {}

card::card(unsigned int v, seed_t s) : value_{v}, seed_{s} {
    if (value_ > 10) throw std::exception{};
}

bool card::value(unsigned int v) {
    if (v > 10) return false;
    this->value_ = v;
    return true;
}

[[nodiscard]] unsigned int card::value() const {
    return this->value_;
}

void card::seed(seed_t s) {
    this->seed_ = s;
}

[[nodiscard]] seed_t card::seed() const {
    return this->seed_;
}

[[nodiscard]] std::string card::to_string() const {
    std::ostringstream oss;
    oss << "{ " << this->value() << ", " << seed_to_str(this->seed()) << " }";
    return oss.str();
}

void swap(card &c1, card &c2) {
    using std::swap;
    swap(c1.value_, c2.value_);
    swap(c1.seed_, c2.seed_);
}