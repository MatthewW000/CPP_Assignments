#include "Map.h"
#include "Player.h"
#include "Item.h"
#include "Game.h"
#include "GameEnums.h"
#include "Holocron_01.h"

#include <random>
#include <vector>

#include <iostream>


Map::Map() {
    SetPlayerPosition(0, 0);
    PopulateEnemies();
    PopulateItems();
};

Map::~Map() {}

void Map::SetPlayerPosition(int x, int y) {
    //first a for loop to clear the current player pos. bool.
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            rooms[i][j].hasPlayer = false;
        }
    }

    //then we can set
    //avoid out of bounds measures within our 10 x 10 map
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight)
    {
        rooms[y][x].hasPlayer = true; // JFC y is rows and X IS FKIN COLUMNS DONT SPEND 2 HOURS ON THIS AGAIN !!
    }
}


void Map::PopulateItems() {
    Holocron_01* H = new Holocron_01();
    PlaceItem(H, 1, 1);
}

void Map::PlaceItem(Item* item, int x, int y) {
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
        rooms[y][x].item = item;
    }
}


void Map::PopulateEnemies() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, mapWidth - 1);
    std::uniform_int_distribution<> disY(0, mapHeight - 1);

    for (int i = 0; i < 5; i++) {
        int x, y;
        do {
            x = disX(gen);
            y = disY(gen);
        } while (!IsPositionEmpty(x, y));

        rooms[y][x].hasEnemy = true; // Simplification for example
    }
}

bool Map::IsPositionEmpty(int x, int y) const {
    // Check if the position is empty (i.e., no other enemies and not the player's start position)
    if (x == 0 && y == 0) return false; // Assuming player starts at (0,0)
    for (const auto& enemy : enemies) {
        if (enemy.xPosition == x && enemy.yPosition == y) return false;
    }
    return true;
}


void Map::Render() const {
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            rooms[i][j].Render();
        }
        cout << endl;
    }
}

