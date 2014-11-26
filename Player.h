// File: Player.h
// Author: Timothy Kiyui (4316886)

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Tile.h"
#include <string>

using namespace std;

class Tile;

class Player
{
    private:
        // Current tile
        Tile* _isOn;
        // Player's name
        string _name;
    public:
        // Constructor
        Player(string name);
        // Moves the player by rolling the dice
        void move(Dice *die);
        // Places player on a tile
        void place_on(Tile *t);
        // Gets current tile
        Tile* get_on();
        // Returns the player name
        string str();
};
#endif
