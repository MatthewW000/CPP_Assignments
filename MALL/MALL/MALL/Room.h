#pragma once
#include "Item.h" // Make sure this include is correct and Item class is properly defined and accessible
#include <string>

class Room {
public:
    std::string description;
    bool hasPlayer;
    bool hasEnemy;
    Item* item; // Assuming Item is properly defined elsewhere

    Room();
    ~Room();

    void Render() const;
};
