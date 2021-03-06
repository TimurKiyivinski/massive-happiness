// File: Die.cpp
// Author: Timothy Kiyui (4316886)

#include "Die.h"
#include <cstdlib>
#include <ctime>

Die::Die(int sides): _sides(sides)
{
    // Create a seed
    srand (time(NULL));
    // Create an initial value for the die
    roll();
}

void Die::roll()
{
    // Create a random value from range 1 - _sides
    _top_value = (rand() % _sides) + 1;
}

int Die::get_top_value() { return _top_value; }

int Die::get_sides() { return _sides; }
