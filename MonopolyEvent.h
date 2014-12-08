// File: MonopolyEvent.h
// Author: Timothy Kiyui (4316886)

#ifndef MONOPOLYEVENT_H
#define MONOPOLYEVENT_H

#include "EventKind.h"
#include "Player.h"
#include <string>

using namespace std;

// A simple class to represent any event that happens in the game
class MonopolyEvent
{
    public:
        // The player this event occured to
        Player* player;
        // A description of the event
        string description;
        // The kind of event
        EventKind kind;
        // Related data to the event
        void* other;
        // Returns a description of the event
        string str();
};
#endif
