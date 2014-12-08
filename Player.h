// File: Player.h
// Author: Timothy Kiyui (4316886)

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Tile.h"
#include <string>

using namespace std;

class Tile;

class MonopolyGame;

class Player
{
    private:
        // Current tile
        Tile* _isOn;
        // Player's name
        string _name;
        // Current game
        MonopolyGame *_playing;
        // Current cash
        int _cash;
    public:
        // Constructor
        Player(string name, MonopolyGame *game);
        // Places player on a tile
        void place_on(Tile *t);
        // Moves the player by rolling the dice
        void move(Dice *die);
        // Moves the player by distance
        void move(int dist, string desc);
        // Gets current tile
        Tile* get_on();
        // Returns the player name
        string str();
        // Changes cash
        void change_cash(int deltacash, string desc);
        // Gets current cash
        int cash();
};
#endif
