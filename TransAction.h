// File: TransAction.h
// Author: Timothy Kiyui (4316886)

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Action.h"
#include <string>

using namespace std;

class TransAction: public Action
{
    private:
        int _value;
        string _description;
    public:
        TransAction(int val, string desc);
        void perform(Player *p);
};
#endif
