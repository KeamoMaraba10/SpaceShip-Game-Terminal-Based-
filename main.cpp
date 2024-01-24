#include <iostream>
#include "libShipSpace.h"

using namespace std;

int main() {
    int ship_position;
    int fuel_sources[FUEL_SOURCES];
    int fuel_level;

    initialize_game(ship_position, fuel_sources, fuel_level);

    while (fuel_level > 0 && (ship_position != 0 && ship_position != SEA_LENGTH - 1)) {
        display_game(ship_position, fuel_sources, fuel_level);
        move_ship(ship_position, fuel_sources, fuel_level);
    }

    if (fuel_level <= 0) {
        cout << "LOSER!! YOU RAN OUT OF GAS BRUH.\n";
    } else {
        cout << "NICE WORK! YOU WON SOMETHING FOR A CHANGE.\n";
    }

    return 0;
}
