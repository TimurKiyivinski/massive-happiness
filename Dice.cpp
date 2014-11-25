// File: Die.h
// Author: Timothy Kiyui (4316886)

#include "Dice.h"
#include "Die.h"
#include <cstdlib>
#include <vector>

using namespace std;

Dice::Dice() {}

Dice::~Dice()
{
    for (Die *d: _die)
        delete d;
    _die.clear();
}

void Dice::add_dice(Die *d)
{
    if (d != NULL)
        _die.push_back(d);
}

void Dice::roll()
{
    for (Die *d: _die)
        d->roll();
}

Die* Dice::die_at(int idx)
{
    if (idx < _die.size())
        return _die[idx];
    return NULL;
}

int Dice::get_total_value()
{
    int value(0);
    for (Die *d: _die)
        value += d->get_top_value();
    return value;
}

bool Dice::all_same()
{
    if (_die.size() == 1) return true;
    if (_die.size() > 1)
    {
        int value = _die[0]->get_top_value();
        for (int loopVar(1); loopVar < _die.size(); loopVar++)
        {
            if (_die[loopVar]->get_top_value() != value) return false;
        }
    }
    return true;
}
