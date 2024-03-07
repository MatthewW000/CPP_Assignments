#pragma once

#include "Room.h" // Assuming Room is another class you have defined
#include "Item.h" // Assuming Item class exists and has HealthPotion as a derived class
#include "Enemy.h" // Assuming Enemy class exists
#include "Holocron_01.h"
#include <vector>

using namespace std;

class Item;

class Map {
public:
    static const int mapWidth = 10;
    static const int mapHeight = 10;

    Map();
    ~Map();

    void SetPlayerPosition(int x, int y);
    void PopulateItems();
    void PlaceItem(Item* item, int x, int y);
    void PopulateEnemies();
    bool IsPositionEmpty(int x, int y) const;
    void Render() const;

    std::vector<Enemy> enemies;
    Room rooms[mapWidth][mapHeight];
private:
};