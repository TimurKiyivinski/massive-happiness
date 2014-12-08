// File: TransAction.cpp
// Author: Timothy Kiyui (4316886)

#include "TransAction.h"
#include "Player.h"
#include <string>

using namespace std;

TransAction::TransAction(int val, string desc):
    _value(val), _description(desc)
{}

// Performs a transaction on the player
void TransAction::perform(Player *p)
{
    p->change_cash(_value, _description);
}
