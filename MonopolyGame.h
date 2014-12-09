// File: MonopolyGame.h
// Author: Timothy Kiyui (4316886)

#ifndef MONOPOLYGAME_H
#define MONOPOLYGAME_H

#include "Board.h"
#include "Dice.h"
#include "Tile.h"
#include "Action.h"
#include <vector>

using namespace std;

class Board;

class Player;

class MonopolyEvent;

// The entire game is controlled by this class, from rolling the dice to moving
// players and managing different actions as well as annoucements. It is also
// responsible for freeing all allocated memory in the game.
class MonopolyGame
{
    private:
        // Current game board
        Board *_board;
        // Dice for the monopoly game,
        // consists of two die
        Dice *_dice;
        // All players int the game
        vector<Player*> _players;
        // Current game player index
        int _current_player_idx;
        // Collection of all added actions, for memory management
        vector<Action*> _actions;
        // Creates the board privately
        void create_board();
        // Creates the two die for the game
        void create_dice();
        // Sets up actions on tiles accordingly
        void setup_board_actions();
    public:
        // Constructor
        MonopolyGame();
        // Destructor
        ~MonopolyGame();
        // Returns the current player
        Player *current_player();
        // Gets the total number of players
        int player_count();
        // Returns the dice pointer
        Dice *get_dice();
        // Returns the board pointer
        Board *get_board();
        // Adds a new playing character
        void add_player(Player *p);
        // Gets the player at a certain index
        Player *player_at(int idx);
        // Steps the game /  next player's turn
        void perform_move();
        // Announces a monpoly event to stdout
        void announce_monopoly_event(MonopolyEvent evt);
};
#endif
