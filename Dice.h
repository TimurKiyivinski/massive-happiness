// File: Dice.h
// Author: Timothy Kiyui (4316886)

#ifndef DICE_H
#define DICE_H

#include "Die.h"
#include <vector>

class Dice
{
    private:
        vector<Die*> _die;
    public:
        Dice();
        ~Dice();
        void add_dice(Die *d);
        void roll();
        Die* die_at(int idx);
        int get_total_value();
        bool all_same();
};
#endif
