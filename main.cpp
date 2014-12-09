// File: main.cpp
// Author: Timothy Kiyui (4316886)

#include "Action.h"
#include "Board.h"
#include "Dice.h"
#include "Die.h"
#include "EventKind.h"
#include "MonopolyEvent.h"
#include "MonopolyGame.h"
#include "MoveAction.h"
#include "Player.h"
#include "Tile.h"
#include "TransAction.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// I'm lazy
#define println(a) cout << a << endl;

int main(void)
{
    MonopolyGame *game = new MonopolyGame();
    string userInput;
    while (game->player_count() < 1 || userInput != "quit")
    {
        if (game->player_count() > 0)
            cout << "Type quit as player name to exit:" << endl;
        cout << "Please input player name:" << endl;
        cin >> userInput;
        if (userInput != "quit")
        {
            Player *p = new Player(userInput, game);
            game->add_player(p);
        }
    }
    char input;
    // Main game loop
    bool gameLoop(true);
    while (gameLoop)
    {
        Player *p = game->current_player();
        println("\nCurrent player:");
        println(p->str());
        println("* Simple Monopoly (alpha):");
        println("* r/R\tRoll Dice");
        println("* t/T\tView Tile");
        println("* q/Q\tQuit\n");
        cin >> input;
        cout << "\n#Your selection: " << input << endl;
        switch(input)
        {
            case 'r': case 'R':
                {
                    // Rolls the dice and moves the player based on the outcome
                    println("\n~Rolling dice!");
                    game->perform_move();
                    break;
                }
            case 't': case 'T':
                {
                    // Gets information about current tile
                    println("\n~Tile:");
                    Tile *playerTile = p->get_on();
                    println(playerTile->str());
                    break;
                }
            case 'q': case 'Q':
                {
                    // Leave the game
                    println("\n~Goodbye!");
                    gameLoop = false;
                    break;
                }
            default:
                println("\nInvalid input.\n");
                break;
        }
    }
    delete game;
    return 0;
}
