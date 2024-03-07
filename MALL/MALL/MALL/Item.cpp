#include "Item.h"
#include "String.h"
#include "Player.h"
#include "Holocron_01.h"

#include <iostream> // For std::cout
#include <cstdlib>  // For std::exit

Item::Item() {}
Item::~Item() {}

char Item::GetRepresentation() const {
    return ' ? ';
}

//void HealthPotion::Use(Player& player) {
//    String nothing;
//    player.health += 10;
//    std::cout << "Your health has increased by 10." << std::endl;
//    nothing.ReadFromConsole();
//}
//
//void ManaPotion::Use(Player& player) {
//    String nothing;
//    player.mana += 10;
//    std::cout << "Your mana has increased by 10." << std::endl;
//    nothing.ReadFromConsole();
//}