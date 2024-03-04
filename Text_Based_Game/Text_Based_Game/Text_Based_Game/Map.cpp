#include "Map.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

//Constructor
Map::Map(int size) :size(size), playerX(-1), playerY(-1) {
	Initialize();
}

//Destructor
Map::~Map() {
	for (int i = 0; i < size; i++)
	{
		delete[] map; //delete the arrays
	}
	delete[] map;
}

/// <summary>
/// A helper function to initialize the first empty map.
/// </summary>
void Map::Initialize() {
	map = new char* [size]; // Allocate rows
	for (int i = 0; i < size; i++)
	{
		map[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			map[i][j] = '-'; // initialize a placeholder to show nothing at that tile when beginning
		}
	}
}

void Map::SetPlayerPosition(int x, int y) {
	// Later we will add functionality to clear the old player position.
	playerX = x;
	playerY = y;
}


/// <summary>
/// A Print function to print the current elements around the map.
/// </summary>
void Map::Print() const {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == playerY && j == playerX) {
				cout << "P "; // Print 'P' for the player's position
			}
			else {
				cout << map[i][j] << " ";
			}
		}
		cout << endl;
	}
}