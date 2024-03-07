#pragma once
#include "Item.h"
#include "Player.h"

class Holocron_01 : public Item {
public:
    Holocron_01() {};
    ~Holocron_01() {};
    virtual void Use(Player& player) override;
};

