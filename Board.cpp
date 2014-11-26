// File: Board.h
// Author: Timothy Kiyui (4316886)

#include "Board.h"
#include "Tile.h"
#include <vector>

Board::~Board()
{
    // Frees the memory of all tiles
    for (Tile *t: _tiles)
        delete t;
    // Clears the vector
    _tiles.clear();
}

void Board::add_tile(Tile *t)
{
    // Adds a new tile if it isn't empty
    if (t != NULL)
        _tiles.push_back(t);
}

Tile* Board::tile_at(int idx)
{
    // Returns the tile at the specific index
    if (idx < _tiles.size())
        return _tiles[idx];
    return NULL;
}

Tile* Board::tile_named(string name)
{
    // Iterates until it finds a tile with the specified name
    for (Tile *t: _tiles)
        if (t->get_name() == name)
            return t;
    return NULL;
}

int Board::tile_count() { return _tiles.size(); }

Tile*& Board::operator[](int index)
{
    return _tiles[index];
}
