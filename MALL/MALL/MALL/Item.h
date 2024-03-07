#pragma once
#include "Player.h"
#include "String.h" // Only include if you use String in Item interface directly
using namespace std;

class Item {
public:

    Item();
    virtual ~Item();
    virtual void Use(Player& player) = 0;
    virtual char GetRepresentation() const;
};

//1 create new .h and .cpp file for holocron, HP, MP



class HealthPotion : public Item {
public:
    void Use(Player& player) override;
};

class ManaPotion : public Item {
public:
    void Use(Player& player) override;
};

