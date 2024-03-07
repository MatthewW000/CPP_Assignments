#pragma once
#include "Item.h" // Make sure this include is correct and Item class is properly defined and accessible
#include <string>

class Item;

class Room {
public:
    string description;
    bool hasPlayer;
    bool hasEnemy;
    Item* item; 

    Room();
    ~Room();

    void Render() const;
};
