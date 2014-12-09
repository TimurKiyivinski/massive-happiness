//File: Action.h
//Author: Timothy Kiyui (4316886)

#ifndef ACTION_H
#define ACTION_H

class Player;

// An abstract class to perform actions on the player through
// inherited methods.
class Action
{
    public:
        virtual void perform(Player *p)=0;
};
#endif
