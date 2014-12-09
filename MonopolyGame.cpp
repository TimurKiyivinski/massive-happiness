// File: MonopolyGame.cpp
// Author: Timothy Kiyui (4316886)

#include "MonopolyGame.h"
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Action.h"
#include "TransAction.h"
#include "MoveAction.h"
#include "MonopolyEvent.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void MonopolyGame::create_board()
{
    // Creates a file stream
    ifstream myCSV("MonopolyBoard.csv");
    // Creates a new board
    _board = new Board();
    // Loop through the file line by line
    for (string csvLine; getline(myCSV, csvLine);)
    {
        stringstream lineStream(csvLine);
        string _value;
        vector<string> _values;
        // Split values by the comma
        while (getline(lineStream, _value, ','))
        {
            _values.push_back(_value);
        }
        // Create a new tile based on information
        Tile *t = new Tile(_values[2]);
        // Add tile to board
        _board->add_tile(t);
    }
    // Iterates through tiles and sets next tile
    for (int i(0); i < _board->tile_count(); i++)
    {
        Tile *t = (*_board)[i];
        if (i == _board->tile_count() - 1)
            t->set_next((*_board)[0]);
        else
            t->set_next((*_board)[i + 1]);
    }
}

void MonopolyGame::create_dice()
{
    // Create two 6 sided die
    Die *dieOne = new Die(6);
    Die *dieTwo = new Die(6);
    // Add them to a new Dice
    _dice = new Dice();
    _dice->add_dice(dieOne);
    _dice->add_dice(dieTwo);
}

// Sets up actions for tiles
void MonopolyGame::setup_board_actions()
{
    Action *_go = new TransAction(200, "Player has passed GO");
    Action *_tax = new TransAction(-60, "Income Tax");
    // Adds to actions vector
    _actions.push_back(_go);
    _actions.push_back(_tax);
    // Special actions for GO and Income Tax
    Tile *t_go = _board->tile_named("GO");
    Tile *t_tax = _board->tile_named("Income Tax");
    t_go->set_pass_action(_go);
    t_tax->set_land_action(_tax);
}

// Constructor
MonopolyGame::MonopolyGame():
    _current_player_idx(0)
{
    // Creates the current board
    create_board();
    // Creates dice for the game
    create_dice();
    // Sets up tile actions
    setup_board_actions();
}

// Free all allocated memory
MonopolyGame::~MonopolyGame()
{
    delete _board;
    delete _dice;
    for (Player *p: _players)
        delete p;
    for (Action *a: _actions)
        if (a != NULL)
            delete a;
}

// Returns player at current index, _current_player_idx
Player* MonopolyGame::current_player()
{
    return _players[_current_player_idx];
}

// Returns the size of the player vector as it is
// essentially the total player count
int MonopolyGame::player_count()
{
    return _players.size();
}

// Returns dice pointer
Dice* MonopolyGame::get_dice() { return _dice; }

// Returns board pointer
Board* MonopolyGame::get_board() { return _board; }

// Adds a player into the _players vector
void MonopolyGame::add_player(Player *p)
{
    p->place_on((*_board)[0]);
    _players.push_back(p);
}

// Returns the player at a given index
Player* MonopolyGame::player_at(int idx) { return _players[idx]; }

// Performs a move
void MonopolyGame::perform_move()
{
    // Rolls the dice
    _dice->roll();
    MonopolyEvent _dice_event;
    _dice_event.player = current_player();
    _dice_event.description = "The dice is being rolled!";
    _dice_event.kind = DICE_EVENT;
    _dice_event.other = _dice;
    announce_monopoly_event(_dice_event);
    // Gets and moves the player
    // if they are all same
    if (_dice->all_same())
    {
        Player *_current_player = current_player();
        _current_player->move(_dice);
    }
    // Switches turn
    _current_player_idx++;
    if (_current_player_idx == _players.size())
        _current_player_idx = 0;
}

// Currently uses stdout to print out an event
void MonopolyGame::announce_monopoly_event(MonopolyEvent evt)
{
    cout << evt.str() << endl;
}
