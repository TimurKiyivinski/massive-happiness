//File: Action.h
//Author: Timothy Kiyui (4316886)

#ifndef ACTION_H
#define ACTION_H

class Player;

class Action
{
    public:
        virtual void perform(Player *p)=0;
};
#endif
