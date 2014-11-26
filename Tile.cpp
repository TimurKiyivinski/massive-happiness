// File: Tile.h
// Author: Timothy Kiyui (4316886)

#include "Tile.h"
#include "Dice.h"
#include "Player.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Initializes the tile name
Tile::Tile(string name): _name(name)
{   
}

void Tile::move(Player *p, Dice *d, int remaining)
{
    // If this is the intended tile, move the player to this tile
    if (remaining == 0)
        p->place_on(this);
    else
        _next->move(p, d, --remaining); // Calls the next tile to move player
}

void Tile::land(Player *p)
{
    _players.push_back(p);
}

void Tile::leave(Player *p)
{
    int toRemove(0);
    // Iterate players to find intended one
    for (int i(0); i < _players.size(); i++)
    {
        if (p == _players[i])
        {
            toRemove = i;
            break;
        }
    }
    // Remove the player from the vector
    _players.erase(remove(_players.begin(), _players.end(), p), _players.end());
}

// Sets the next tile
void Tile::set_next(Tile *t)
{
    if (t != NULL)
        _next = t;
}

Tile* Tile::get_next() { return _next; }

string Tile::str()
{
    // Returns the name of the tile
    // and all the players on it
    string returnStr(_name + "\nPlayers:\n");
    for (Player *p: _players)
        returnStr += p->str() + "\n";
    return returnStr;
}

string Tile::get_name() { return _name; }
