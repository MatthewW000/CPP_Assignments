#pragma once

#include "String.h"
#include "GameEnums.h" // Assuming JediClass enum is declared in this file

class Player {
public:
    Player();
    Player(const String& startName, JediClass startClass, int startX, int startY);
    ~Player();

    int GetX() const;
    int GetY() const;
    int GetHealth() const;
    int GetAttack() const;
    int GetDefence() const;
    int GetMana() const;

    void Move(char direction);

    // Public attributes (Consider using getters and setters or ensuring proper encapsulation)
    int health;
    int mana;
    int attack;
    int defence;

private:
    String name;
    JediClass jediClass;
    int xPosition;
    int yPosition;
};
