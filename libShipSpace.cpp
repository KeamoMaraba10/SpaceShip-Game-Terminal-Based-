#include "libShipSpace.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void initialize_game(int& ship_position, int fuel_sources[], int& fuel_level) {
    // Seed the random number generator
    srand(time(0));

    // Place fuel sources at random positions (excluding the middle of the sea)
    for (int i = 0; i < FUEL_SOURCES; i++) {
        int fuel_source_position;
        do {
            fuel_source_position = rand() % SEA_LENGTH;
        } while (fuel_source_position == SEA_LENGTH / 2 || find(fuel_sources, fuel_sources + i, fuel_source_position) != fuel_sources + i);
        fuel_sources[i] = fuel_source_position;
    }

    // Start the ship in the middle position and start with maximum fuel
    ship_position = SEA_LENGTH / 2;
    fuel_level = FUEL_LEVEL_START;
}

void display_game(int ship_position, const int fuel_sources[], int fuel_level) {
    // Display the sea
    for (int i = 0; i < SEA_LENGTH; i++) {
        if (i == ship_position) {
            cout << 'O';
        } else if (find(fuel_sources, fuel_sources + FUEL_SOURCES, i) != fuel_sources + FUEL_SOURCES) {
            cout << '^';
        } else {
            cout << '_';
        }
    }
    cout << '\n';

    // Display the ship's fuel level
    cout << "Fuel level: " << fuel_level << '\n';
}

void move_ship(int& ship_position, int fuel_sources[], int& fuel_level) {
    // Prompt user for move and move the ship
    char move;
    do {
        cout << "Enter move (l for left, r for right): ";
        cin >> move;
    } while (move != 'l' && move != 'r');
    if (move == 'l' && ship_position > 0) {
        ship_position--;
    } else if (move == 'r' && ship_position < SEA_LENGTH - 1) {
        ship_position++;
    }

    // Decrease fuel level by 1 and check for fuel sources
    fuel_level--;
    for (int i = 0; i < FUEL_SOURCES; i++) {
        if (fuel_sources[i] == ship_position) {
            fuel_level += FUEL_LEVEL_INCREASE;
            fuel_sources[i] = -1; // mark fuel source as used
        }
    }
}

