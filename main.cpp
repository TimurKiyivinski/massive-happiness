#include "Die.h"
#include <iostream>

using namespace std;

// I'm lazy
#define println(a) cout << a << endl;

int main(void)
{
    int sideNo(-1);
    char input;
    while (sideNo < 2) // Create the first Die, sides must be more than 1
    {
        println("Please input the number of sides for Die 1:");
        cin >> sideNo;
    }
    Die *dieOne = new Die(sideNo);
    sideNo = -1;
    while (sideNo < 2) // Create the second Die, sides must be more than 1
    {
        println("Please input the number of sides for Die 2:");
        cin >> sideNo;
    }
    Die *dieTwo = new Die(sideNo);
    // Main loop for user input
    while (input != 'q' && input != 'Q')
    {
        println("\nInput:\nR: Roll dice\nV: View dice\nQ: Quit\n");
        cout << "Input: ";
        cin >> input;
        switch (input)
        {
            case 'r': case 'R':
                // Roll the dice to get new values
                println("Rolling dice!");
                dieOne->roll();
                dieTwo->roll();
                break;
            case 'v': case 'V':
                // Print the top values of each die
                println("Top values:");
                println("Die One:");
                println(dieOne->get_top_value());
                println("Die Two:");
                println(dieTwo->get_top_value());
                break;
            case 'q': case 'Q':
                println("Goodbye!");
                break;
            default:
                println("Invalid input!");
        }
    }
    return 0;
}
