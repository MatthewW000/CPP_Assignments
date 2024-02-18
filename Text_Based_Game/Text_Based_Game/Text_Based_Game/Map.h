#pragma once
class Map
{
public:
	Map(int _size); // Constructor to take map size
	~Map(); // Destructor to clean up memory

	void Print() const; // Print map function

private:
	int size = 0; // map size
	char** map; //2D Array for the map

	void Initialize(); // Helper function to init map
};

