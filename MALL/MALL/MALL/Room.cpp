#include "Room.h"
#include "Item.h"
#include "Game.h"
#include "GameEnums.h"

#include <iostream>
#include <string>

using namespace std;



string description;
bool hasPlayer;
bool hasEnemy; //trying this with a pointer to an enemy cause truck the other way
Item* item;
//later will add more properties and methods here for items, enemy dark jedi etc.


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
        std::cout << item->GetRepresentation();
    }
    else {
        std::cout << description;
    }
}