// File: Dice.cpp
// Author: Timothy Kiyui (4316886)

#include "Dice.h"
#include "Die.h"
#include <cstdlib>
#include <vector>

using namespace std;

// Empty constructor as nothing needs to be initialized
Dice::Dice() {}

Dice::~Dice()
{
    // Loops through all dies and frees the memory
    for (Die *d: _die)
        delete d;
    // Empties the vector
    _die.clear();
}

void Dice::add_dice(Die *d)
{
    // Adds a die to the _die vector
    // if it is not nothing
    if (d != NULL)
        _die.push_back(d);
}

void Dice::roll()
{
    // Iterates and rolls all dies
    for (Die *d: _die)
        d->roll();
}

Die* Dice::die_at(int idx)
{
    // Returns a die at an index or returns NULL
    if (idx < _die.size())
        return _die[idx];
    return NULL;
}

int Dice::get_total_value()
{
    // Iterates and adds up the face value of all dies
    int value(0);
    for (Die *d: _die)
        value += d->get_top_value();
    return value;
}

bool Dice::all_same()
{
    // If there is only one die, all have the same top value
    if (_die.size() == 1) return true;
    // Compare all dies to the first die
    int value = _die[0]->get_top_value();
    for (int loopVar(1); loopVar < _die.size(); loopVar++)
    {
        // Return false if a different value is encountered
        if (_die[loopVar]->get_top_value() != value) return false;
    }
    return true;
}
