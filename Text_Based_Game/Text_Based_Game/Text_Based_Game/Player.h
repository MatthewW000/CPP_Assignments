#ifndef PLAYER_H
#define PLAYER_H
#include "String.h"


#pragma once
class Player
{
public:
	Player(int health, int attack, int mana);
	virtual ~Player();

	void Move(const String& direction);

    int GetX() const;
    int GetY() const;

private:
    int health;
    int attack;
    int mana;
    bool ultimateMove;

    int x, y; // Player's position
};

#endif // PLAYER_H