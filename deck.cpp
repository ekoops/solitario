#include "deck.h"

deck::deck(): cards_ {} {
    for (int i=0; i<DIM; i++) {
        cards_[i].value((i % 10) + 1);
        seed_t s;
        if (i < 10) s = seed_t::BASTONI;
        else if (i < 20) s = seed_t::COPPE;
        else if (i < 30) s = seed_t::DENARI;
        else s = seed_t::SPADE;
        cards_[i].seed(s);
    }
}
[[nodiscard]] std::array<card, DIM> const& deck::get_cards() const {
    return this->cards_;
}

void deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine g {seed};
    std::uniform_int_distribution<int> d(0,40);
    for (int i=0; i<DIM-1; i++) {
        int j = DIM-i-1;
        int k = d(g) % j;
        std::swap(cards_[j], cards_[k]);
    }
}
void deck::print() {
    std::ostringstream oss;
    oss << "Deck:\n";
    for (auto& c: this->cards_) {
        oss << c.to_string() << '\n';
    }
    oss << '\n';
    std::cout << oss.str();
}