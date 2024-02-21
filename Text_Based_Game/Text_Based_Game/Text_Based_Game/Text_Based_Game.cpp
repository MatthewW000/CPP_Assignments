#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include "Player.h"
#include "Map.h" // Make sure to include the Map class header
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    // ASCII Art for "MALL"
    cout << R"(
 __  __    _    _      _    
|  \/  |  / \  | |    | |   
| |\/| | / _ \ | |    | |   
| |  | |/ ___ \| |___ | |___
|_|  |_/_/   \_\_____||_____|
                             
)" << endl;

    // Welcome Message
    cout << "Welcome to MALL, mortal." << endl;

    // Prompt for difficulty selection
    cout << "Select difficulty (1: Easy, 2: Hard, 3: Nightmare): ";
    int choice;
    cin >> choice;

    int mapSize;
    switch (choice) {
    case 1:
        mapSize = 3; // Easy
        break;
    case 2:
        mapSize = 5; // Hard
        break;
    case 3:
        mapSize = 20; // Nightmare
        break;
    default:
        cout << "Invalid choice. Defaulting to Easy.";
        mapSize = 3;
    }

    // Initialize the map with the chosen size
    Map gameMap(mapSize);
    gameMap.Print(); // Display the initial map

    //Initialize a player 
    Player player (100, 10, 50); // has standard health, mana, attack features.
    //player.SetPosition(0, 0);

    // Initialize your custom String class for player input
    String playerInput;

    while (true) {
        cout << "Type 'run away' to exit the game" << endl;

        // Use the ReadFromConsole method of your String class to get input
        playerInput.ReadFromConsole();

        // Convert the input to lowercase to handle case-insensitive comparison
        playerInput.ToLower();

        // Check if the player wants to quit the game by typing "run away"
        if (playerInput.EqualTo("run away")) {
            cout << "You flee to the outskirts, never to return to MALL." << endl;
            break; // Exit the loop and end the game
        }
        else if (playerInput.Find("move ") == 0) { // Check if the command starts with "move "
            // Extract direction part of the command
            String direction = playerInput; // Copy the full command first
            direction.Replace("move ", ""); // Remove "move " to get just the direction

            player.Move(direction); // Move the player based on the extracted direction
            //gameMap.Print(); // commented out for now to see when is best time to update map.
        }

        //Update the map
        gameMap.SetPlayerPosition(player.GetX(), player.GetY());
        gameMap.Print();

        // Here, you can add more code to handle other commands
        // For example, move the player, interact with the map, etc.
        cout << "--- Code and text ---" << endl;
    }

    return 0;
}