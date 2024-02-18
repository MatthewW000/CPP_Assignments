#include "String.h"
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
            cout << "You flee to the outskirts, never to return to MALL" << endl;
            break; // Exit the loop and end the game
        }

        // Here, you can add more code to handle other commands
        cout << "--- Code and text ---" << endl;
    }

    return 0;
}
