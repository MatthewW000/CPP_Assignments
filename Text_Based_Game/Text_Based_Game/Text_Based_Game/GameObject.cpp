// GameObject.h
#ifndef GAME_OBJECT_H // If GAME_OBJECT_H is not defined
#define GAME_OBJECT_H // Define GAME_OBJECT_H

class GameObject {
public:
    // Attributes common to all game objects
    int x, y; // Position
    bool isVisible;

    // Constructor
    GameObject(int posX = 0, int posY = 0, bool visible = true) : x(posX), y(posY), isVisible(visible) {}

    // Virtual destructor to ensure derived class destructors are called
    virtual ~GameObject() {}

    // Virtual method for updating the object
    virtual void Update() = 0;

    // Virtual method for drawing the object (if your game has a visual representation in console or otherwise)
    virtual void Draw() const = 0;

    // You can add more common functionality here
};

#endif // End the ifdef condition
