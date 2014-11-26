// File: Dice.h
// Author: Timothy Kiyui (4316886)

#ifndef DICE_H
#define DICE_H

#include "Die.h"
#include <vector>

using namespace std;

class Dice
{
    private:
        // Contains all dies
        vector<Die*> _die;
    public:
        // Constructor
        Dice();
        // Frees all contained dies
        ~Dice();
        // Adds a new die
        void add_dice(Die *d);
        // Rolls all contained dies
        void roll();
        // Returns the die at a certain index
        Die* die_at(int idx);
        // Returns the sum of all die top values
        int get_total_value();
        // Returns the boolean if all dies have the
        // same face value.
        bool all_same();
};
#endif
