#include "board.h"

void board::place(card const& c) {
    cards_.push_back(c);
}

void board::compact(bool has_to_print) {
    size_t size = this->cards_.size();
    if (size < 3) return;
    for (int i=1; i<=size-2; i++) {
        auto& previous = this->cards_[i-1];
        auto& next = this->cards_[i+1];
        if (previous.seed() == next.seed() || previous.value() == next.value()) {
            this->cards_.erase(this->cards_.begin() + (i-1));
            if (has_to_print) this->print();
            return this->compact(has_to_print);
        }
    }
}

[[nodiscard]] unsigned int board::length() const {
    return this->cards_.size();
}

void board::print() {
    std::ostringstream oss;
    for (auto& c: this->cards_) {
        oss << c.to_string();
    }
    oss << '\n';
    std::cout << oss.str();
}