#include "Player.h"
#include <iostream>
#include "String.h"

Player::Player(int health, int attack, int mana) : health(health), attack(attack),
mana(mana), ultimateMove(true), x(0), y(0) {

};

Player::~Player() {

}

void Player::Move(const String& direction) {
    // Assuming CStr() returns a const char* for the underlying C-string
    const char* command = direction.CStr();

    if (strcmp(command, "move left") == 0) {
        x -= 1;
    }
    else if (strcmp(command, "move right") == 0) {
        x += 1;
    }
    else if (strcmp(command, "move up") == 0) {
        y -= 1;
    }
    else if (strcmp(command, "move down") == 0) {
        y += 1;
    }
    else {
        std::cout << "Invalid move command." << std::endl;
    }
}

int Player::GetX() const {
    return x;
}

int Player::GetY() const {
    return y;
}