#pragma once

#include "Player.h" // Include Player header
#include "Room.h"   // Include Room header
#include "Map.h"    // Include Map header
#include "String.h" // If you're using a custom String class, include it here

using namespace std;

class Map;

class Game {
private:
    Map gameMap;
    Player player;
public:
    Game();
    ~Game();
    void ClearScreen();
    void Battle(Player& player, Room& room);
    void Run();
};