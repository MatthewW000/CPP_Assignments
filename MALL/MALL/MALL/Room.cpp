#include "Room.h"
#include "Item.h"
#include "Game.h"
#include "GameEnums.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor
Room::Room() : description(" - "), hasPlayer(false), hasEnemy(false), item(nullptr) {
}

// Destructor
Room::~Room() {
    delete item; 
}

// Render method
void Room::Render() const {
    if (hasPlayer) {
        std::cout << " P ";
    }
    else if (hasEnemy) {
        std::cout << " S "; // Represent stormtrooper
    }
    else if (item != nullptr) {
        std::cout << " ? ";
    }
    else {
        std::cout << description;
    }
}