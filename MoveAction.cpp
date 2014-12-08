// File: MoveAction.cpp
// Author: Timothy Kiyui (4316886)

#include "MoveAction.h"
#include "Player.h"
#include <string>

using namespace std;

// Constructor
MoveAction::MoveAction(int dist, string desc):
    _distance(dist), _description(desc)
{}

// Moves the player accoringly
void MoveAction::perform(Player *p)
{
    p->move(_distance, _description);
}
