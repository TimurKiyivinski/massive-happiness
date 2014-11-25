// File: main.cpp
// Author: Timothy Kiyui (4316886)

#include "Die.h"
#include "Dice.h"
#include <iostream>

using namespace std;

// I'm lazy
#define println(a) cout << a << endl;

int main(void)
{
    char input;
    // Two normal die
    Die *dieOne = new Die(6);
    Die *dieTwo = new Die(6);
    Dice *myDice = new Dice();
    myDice->add_dice(dieOne);
    myDice->add_dice(dieTwo);
    // Main loop to test myDice
    for (int loopVar(0); loopVar < 10; loopVar++)
    {
        println("Total value:");
        println(myDice->get_total_value());
        println("Values the same:");
        myDice->all_same() ?
            (cout << "True" << endl):
            (cout << "False" << endl);
        myDice->roll();
    }
    return 0;
}
