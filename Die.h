// File: Die.h
// Author: Timothy Kiyui (4316886)

#ifndef DIE_H
#define DIE_H
class Die
{
    private:
        int _sides;
        int _top_value;
    public:
        // Initialize _sides and _top_value
        Die(int sides);
        // Rolls the die to generate a new _top_value
        void roll();
        // Get methods
        int get_top_value();
        int get_sides();
};
#endif
