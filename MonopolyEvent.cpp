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
    returnStr += player->str() + " ";
    switch (kind)
    {
        case DICE_EVENT:
            {
                returnStr += "rolled the dice with value:\n";
                Dice *d = static_cast<Dice*>(other);
                returnStr += itos(d->get_total_value());
                break;
            }
        case PASS_EVENT:
            {
                returnStr += "passed the following tile:\n";
                Tile *t = static_cast<Tile*>(other);
                returnStr += t->str();
                break;
            }
        case LAND_EVENT:
            {
                returnStr += "landed on the following tile:\n";
                Tile *t = static_cast<Tile*>(other);
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
                int *cash = static_cast<int*>(other);
                returnStr += "made a transaction worth: " + itos(*cash);
                break;
            }
        default:
            returnStr += "an unrecognised move.";
    }
    returnStr += "\n";
    return returnStr;
}
