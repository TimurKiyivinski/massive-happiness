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

class MonopolyGame
{
    private:
        Board *_board;
        Dice *_dice;
        vector<Player*> _players;
        int _current_player_idx;
        vector<Action*> _actions;
        void create_board();
        void create_dice();
        void setup_board_actions();
    public:
        MonopolyGame();
        ~MonopolyGame();
        Player *current_player();
        int player_count();
        Dice *get_dice();
        Board *get_board();
        void add_player(Player *p);
        Player *player_at(int idx);
        void perform_move();
        void announce_monopoly_event(MonopolyEvent evt);
};
#endif
