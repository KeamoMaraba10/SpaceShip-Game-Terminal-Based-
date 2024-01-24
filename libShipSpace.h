#ifndef SHIP_GAME_H
#define SHIP_GAME_H

#include <cstdlib>
#include <ctime>
#include <algorithm>

const int SEA_LENGTH = 50;
const int FUEL_SOURCES = 4;
const int FUEL_LEVEL_START = 20;
const int FUEL_LEVEL_INCREASE = 5;

// Initializes the game by placing fuel sources at random positions
// and resetting the ship's fuel level and position
void initialize_game(int& ship_position, int fuel_sources[], int& fuel_level);

// Displays the game entities on the console
void display_game(int ship_position, const int fuel_sources[], int fuel_level);

// Moves the ship left or right according to user input and updates the fuel level
void move_ship(int& ship_position, int fuel_sources[], int& fuel_level);

#endif // SHIP_GAME_H
