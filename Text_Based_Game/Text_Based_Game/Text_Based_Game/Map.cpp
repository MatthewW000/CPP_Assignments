#include "Map.h"
#include <iostream>

using namespace std;

//Constructor
Map::Map(int size) :size(size) {
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


/// <summary>
/// A Print function to print the current elements around the map.
/// </summary>
void Map::Print() const {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << map[i][j] << " "; // Print each cell with a space
		}
		cout << endl; // New line after each row
	}
}