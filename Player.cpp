// File: Player.h
// Author: Timothy Kiyui (4316886)

#include "Player.h"
#include "Tile.h"
#include "Dice.h"
#include <string>

using namespace std;

// Initializes player name
Player::Player(string name): _name(name)
{
    _isOn = NULL;
}

void Player::move(Dice *die)
{
    // Rolls the dice
    die->roll();
    // Player leaves the current tile
    _isOn->leave(this);
    // The tile redirects player to the next tile
    _isOn->move(this, die, die->get_total_value());
}

void Player::place_on(Tile *t)
{
    // Places player on a tile if it is not empty
    if (t != NULL)
    {
        _isOn = t;
        t->land(this);
    }
}

Tile* Player::get_on() { return _isOn; }

// Return the player name only at this stage
string Player::str() { return _name; }
