// File: MonopolyEvent.cpp
// Author: Timothy Kiyui (4316886)

#include "MonopolyEvent.h"
#include <string>
#include <sstream>

using namespace std;

// Convert int to string
string itos(int i)
{
    // Create a simple stream
    stringstream myStream;
    string myString("");
    // Add int into the stream
    myStream << i;
    // Pipe the stream into the string
    myStream >> myString;
    return myString;
}

// Returns a string representation of the event
string MonopolyEvent::str()
{
    string returnStr("The following event occured:\n");
    returnStr += player->str() + " with cash : " + itos(player->cash()) + " ";
    switch (kind)
    {
        case DICE_EVENT:
            {
                returnStr += "rolled the dice with value:\n";
                // Gets the current dice
                Dice *d = static_cast<Dice*>(other);
                // Tells user about the dice actions
                returnStr += itos(d->get_total_value());
                if (d->all_same())
                    returnStr += "\nDice match! Player moves.";
                break;
            }
        case PASS_EVENT:
            {
                returnStr += "passed the following tile:\n";
                // Gets the current tile
                Tile *t = static_cast<Tile*>(other);
                // Tells user about the tile
                returnStr += t->str();
                break;
            }
        case LAND_EVENT:
            {
                returnStr += "landed on the following tile:\n";
                // Gets the current tile
                Tile *t = static_cast<Tile*>(other);
                // Tells user about the tile
                returnStr += t->str();
                break;
            }
        case MOVE_EVENT:
            {
                returnStr += "is moving.";
                break;
            }
        case TRANSACTION_EVENT:
            {
                // Gets cash
                int *cash = static_cast<int*>(other);
                // Tells the player of the transaction
                returnStr += "made a transaction worth: " + itos(*cash);
                break;
            }
        default:
            returnStr += "an unrecognised move.";
    }
    returnStr += "\n";
    return returnStr;
}
