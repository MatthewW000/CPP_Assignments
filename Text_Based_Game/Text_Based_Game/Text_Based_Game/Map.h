#pragma once
class Map
{
public:
	Map(int _size); // Constructor to take map size
	~Map(); // Destructor to clean up memory

	void Print() const; // Print map function
	void Initialize(); // Helper function to init map
	void SetPlayerPosition(int x, int y);

private:
	int size = 0; // map size
	char** map; //2D Array for the map
	int playerX, playerY; // //player pos within Array

};

