#pragma once

#include "Player.h"
#include "String.h"
#include "Map.h"
#include "GameEnums.h"

#include <iostream>
using namespace std;

Player::Player(const String& startName, JediClass startClass, int startX, int startY)
    : name(startName), jediClass(startClass), xPosition(startX), yPosition(startY) {
    switch (startClass) {
    case JediSentinel:
        health = 100; mana = 25; attack = 25; defence = 25;
        break;
    case JediKnight:
        health = 120; mana = 15; attack = 35; defence = 20;
        break;
    case JediConsular:
        health = 80; mana = 40; attack = 20; defence = 20;
        break;
    case JediShadow:
        health = 90; mana = 20; attack = 25; defence = 35;
        break;
    default:
        // Handle invalid class, if necessary
        break;
    }
}

Player::~Player() {}

int Player::GetX() const { return xPosition; }
int Player::GetY() const { return yPosition; }
int Player::GetHealth() const { return health; }
int Player::GetAttack() const { return attack; }
int Player::GetDefence() const { return defence; }
int Player::GetMana() const { return mana; }

void Player::Move(char direction) {
    int newX = xPosition, newY = yPosition;

    switch (direction) {
    case 'n': newY--; break; // Assuming the top of the map is "north"
    case 's': newY++; break;
    case 'e': newX++; break;
    case 'w': newX--; break;
    default: cout << "Invalid direction." << endl; return;
    }

    //Check boundary here:
    if (newX < 0 || newX >= Map::mapWidth || newY < 0 || newY >= Map::mapHeight)
    {
        cout << "Invalid move: You cannot leave MALL that easily" << endl;
    }
    else {
        xPosition = newX;
        yPosition = newY;
    }
}