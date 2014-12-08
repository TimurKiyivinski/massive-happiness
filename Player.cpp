// File: Player.cpp
// Author: Timothy Kiyui (4316886)

#include "Player.h"
#include "Tile.h"
#include "Dice.h"
#include "EventKind.h"
#include "MonopolyEvent.h"
#include "MonopolyGame.h"
#include <string>

using namespace std;

// Initializes player name
Player::Player(string name, MonopolyGame *game):
    _name(name), _cash(500)
{
    _isOn = NULL;
    _playing = game;
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

void Player::move(Dice *die)
{
    // Announce event
    MonopolyEvent _event;
    _event.player = this;
    _event.description = "The die is being rolled!";
    _event.kind = MOVE_EVENT;
    _playing->announce_monopoly_event(_event);
    // Rolls the dice
    die->roll();
    // Player leaves the current tile
    _isOn->leave(this);
    // The tile redirects player to the next tile
    _isOn->move(this, die, die->get_total_value());
}

void Player::move(int disc, string desc)
{
    // Moves the player
    _isOn->leave(this);
    _isOn->move(this, NULL, disc);
}

// Gets current tile
Tile* Player::get_on() { return _isOn; }

// Return the player name only at this stage
string Player::str() { return _name; }

void Player::change_cash(int deltacash, string desc)
{
    // Announce event
    MonopolyEvent _event;
    _event.player = this;
    _event.description = desc;
    _event.kind = TRANSACTION_EVENT;
    _event.other = &deltacash;
    _playing->announce_monopoly_event(_event);
    // Perform change to cash
    _cash += deltacash;
}

// Returns cash
int Player::cash() { return _cash; }
