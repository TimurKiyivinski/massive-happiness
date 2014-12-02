// File: MonopolyEvent.h
// Author: Timothy Kiyui (4316886)

#ifndef MONOPOLYEVENT_H
#define MONOPOLYEVENT_H

#include "Player.h"
#include "EventKind.h"
#include <string>

using namespace std;

class MonopolyEvent
{
    private:
        Player* player;
        string description;
        EventKind kind;
        void* other;
    public:
        string str();
};

#endif
