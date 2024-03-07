#pragma once
#include "Player.h"
#include "String.h" 
using namespace std;

class Item {
public:

    Item();
    virtual ~Item();
    virtual void Use(Player& player) = 0;
};

