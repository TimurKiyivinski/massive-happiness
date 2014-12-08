// File: Tile.cpp
// Author: Timothy Kiyui (4316886)

#include "Tile.h"
#include "Dice.h"
#include "Player.h"
#include "Action.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Initializes the tile name
Tile::Tile(string name): _name(name)
{
    _pass_action = NULL;
    _land_action = NULL;
}

// Removes actions, if any
Tile::~Tile()
{
    if (_pass_action != NULL)
        delete _pass_action;
    if (_land_action != NULL)
        delete _land_action;
}

void Tile::move(Player *p, Dice *d, int remaining)
{
    // If this is the intended tile, move the player to this tile
    if (remaining == 0)
        p->place_on(this);
    else
    {
        if (_pass_action != NULL)
            _pass_action->perform(p);
        _next->move(p, d, --remaining); // Calls the next tile to move player
    }
}

void Tile::land(Player *p)
{
    // Puts a player on the tile
    _players.push_back(p);
    // Runs the land action if exists
    if (_land_action != NULL)
        _land_action->perform(p);
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

// Returns the tile name
string Tile::get_name() { return _name; }

// Get and set methods for tile actions
Action* Tile::pass_action() { return _pass_action; }

void Tile::set_pass_action(Action* value)
{
    if (value != NULL)
        _pass_action = value;
}

Action* Tile::land_action() { return _land_action; }

void Tile::set_land_action(Action* value)
{
    if (value != NULL)
        _land_action = value;
}
