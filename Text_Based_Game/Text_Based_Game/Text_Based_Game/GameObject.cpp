#include "GameObject.h"
class GameObject
{
public:
	int x, y; // for Pos
	bool isVisible;

	//Con
	GameObject(int PosX = 0, int PosY = 0, bool visible = true) : x(PosX), y(PosY), isVisible(visible) {};

	virtual ~GameObject() {}

	virtual void Update() = 0;

	virtual void Draw() const = 0;
};