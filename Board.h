// File: Board.h
// Author: Timothy Kiyui (4316886)

#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <vector>
#include <string>

using namespace std;

class Tile;

class Board
{
    private:
        // Contains all tiles
        vector<Tile*> _tiles;
    public:
        // Destructor to free tiles
        ~Board();
        // Adds a new tile
        void add_tile(Tile *t);
        // Returns a tile at an index
        Tile* tile_at(int idx);
        // Returns a tile based on the name
        Tile* tile_named(string name);
        // Gets the total number of tiles
        int tile_count();
        // Overload the index operator
        Tile* &operator [](int index);
};

#endif
