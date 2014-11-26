// File: Tile.h
// Author: Timothy Kiyui (4316886)

#ifndef TILE_H
#define TILE_H

#include "Dice.h"
#include "Player.h"
#include <vector>
#include <string>

using namespace std;

class Player;

class Tile
{
    private:
        // Next tile in the board
        Tile* _next;
        // All players on this board
        vector<Player*> _players;
        // The name of the tile
        string _name;
    public:
        // Constructor
        Tile(string name);
        // Moves a player to a certain tile
        void move(Player *p, Dice *d, int remaining);
        // Puts a player in tile's player list
        void land(Player *p);
        // Removes a player in tile's player list
        void leave(Player *p);
        // Sets the next tile
        void set_next(Tile *t);
        // Returns the next tile
        Tile* get_next();
        // Returns the tile description
        string str();
        // Gets the tile name
        string get_name();
};
#endif
