// File: MoveAction.h
// Author: Timothy Kiyui (4316886)

#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "Action.h"
#include "Player.h"
#include <string>

using namespace std;

// Action that occurs to move the player a certain distance
class MoveAction: public Action
{
    private:
        int _distance;
        string _description;
    public:
        MoveAction(int dist, string desc);
        void perform(Player *p);
};
#endif
