// File: main.cpp
// Author: Timothy Kiyui (4316886)

#include "Die.h"
#include "Dice.h"
#include "Tile.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// I'm lazy
#define println(a) cout << a << endl;

// Loads the monopoly board from a .csv file
Board* loadMonopolyBoard(string _dir)
{
    // Creates a file stream
    ifstream myCSV(_dir);
    // Creates a new board
    Board *_board = new Board();
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
    return _board;
}

int main(void)
{
    // Create the initial monopoly board
    Board *gameBoard = loadMonopolyBoard("./MonopolyBoard.csv");
    // Creates a player Timur
    Player *aPlayer = new Player("Timur");
    aPlayer->place_on(gameBoard->tile_at(0));
    // Creates a set of dice for the game
    Die *dieOne = new Die(6);
    Die *dieTwo = new Die(6);
    Dice *aDice = new Dice();
    aDice->add_dice(dieOne);
    aDice->add_dice(dieTwo);
    char input;
    // Main game loop
    while (1)
    {
        println("\n* Simple Monopoly (severely alpha):");
        println("* r/R\tRoll Dice");
        println("* v/V\tView Value");
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
                    aDice->roll();
                    aPlayer->move(aDice);
                    break;
                }
            case 'v': case 'V':
                {
                    // Views the dice value
                    println("\n~Value:");
                    println(aDice->get_total_value());
                    break;
                }
            case 't': case 'T':
                {
                    // Gets information about current tile
                    println("\n~Tile:");
                    Tile *playerTile = aPlayer->get_on();
                    println(playerTile->str())
                    break;
                }
            case 'q': case 'Q':
                {
                    // Leave the game
                    println("\n~Goodbye!");
                    return 0;
                    break;
                }
            default:
                println("\nInvalid input.\n");
                break;
        }
    }
    delete gameBoard;
    delete aDice;
    return 0;
}
