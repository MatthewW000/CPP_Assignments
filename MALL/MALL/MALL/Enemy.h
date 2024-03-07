#pragma once

using namespace std;

class Enemy {
public:
    int xPosition;
    int yPosition;
    char representation;

    Enemy(int x, int y);
    ~Enemy() = default;
};

