#include <iostream>
#include "deck.h"
#include "board.h"

bool play_game(deck& d, bool has_to_print) {
    d.shuffle();
    board b {};
    for (int i=0; i<40; i++) {
        auto& c = d.get_cards()[i];
        b.place(c);
        if (has_to_print) b.print();
        b.compact(has_to_print);
    }
    return b.length() == 2;
}

int main() {
    deck d {};
    int slots = 10;
    int per_slot_attempts = 100'000;
    double average = 0;
    int winnings_counter = 0;
    for (int i=0; i<slots; i++) {
        for (int j=0; j < per_slot_attempts; j++) {
            if (play_game(d, false)) {
                winnings_counter++;
            }
        }
        double percentage = (((double) winnings_counter) / per_slot_attempts) * 100;
        std::cout << "[slot " << i+1 << "] games won: " << percentage << "% ("
            << winnings_counter << '/' << per_slot_attempts << ')' <<  std::endl;
        average += percentage / slots;
        winnings_counter = 0;
    }
    std::cout << "games won in average: " << average << '%' << std::endl;
    return 0;
}
