#include <cstdlib>
#include <iostream>
#include <vector>
#include "String.h"
#include <windows.h>
using namespace std;

//function to allow operator overloading;
std::ostream& operator<<(std::ostream& os, const String& str) {
    // Assuming you have a method CStr() that returns a const char* to the internal string data
    os << str.CStr();
    return os;
}
//Enums
enum JediClass {
    JediSentinel,
    JediKnight,
    JediConsular,
    JediShadow
};

// --- Room class
class Room {
public:
    string description;
    //later will add more properties and methods here for items, enemy dark jedi etc.

    Room() : description("-") {

    }

    void Render() const {
        cout << description << " ";
    }
};
// -- End Room class

// --- Map class
class Map {
private:
    static const int mapWidth = 10;
    static const int mapHeight = 10;
    Room rooms[mapWidth][mapHeight];//2D array of Room objects
public:
    Map() {}; // nothing to render yet as we are just going to initialize it with a 
    //default setting from the beginning

    void Render() const {
        for (int  i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                rooms[i][j].Render();
            }
            cout << endl;
        }
    }
};

class Player {
private:
    String name;
    int xPosition;
    int yPosition;
    int health;
    int mana; //will add functionality to this later
    int attack; // will add funcitonality to this later
    int defence; // will add functionality to this later

public:
    //Constructor to initialize attributes
    Player(String startName, int startX, int startY, int startHealth, int startMana, int startAttack, int startDefence) : name(startName), xPosition(startX), yPosition(startY), health(startHealth), mana(startMana), attack(startAttack), defence(startDefence) {};

    //Getters for player position within the map
    int GetX() const { return xPosition; }
    int GetY() const { return yPosition; }
    int GetHealth() const { return health; }

    //Method to move the player
    void Move(char direction) {
        switch (direction) {
        case 'n': yPosition--; break; // Assuming the top of the map is "north"
        case 's': yPosition++; break;
        case 'e': xPosition++; break;
        case 'w': xPosition--; break;
        default: cout << "Invalid direction." << endl;
        }
    }
};


class Item;
class Enemy;

class Game {

private:
    Map gameMap; // add this as a member of the game class
    Player player; // init the player in game constructor
public:
    Game() : player(" ", 0, 0, 0, 0, 0, 0) {
        //Map gets initialized here
    }

    void Run() {
        bool gameRunning = true;
        String playerInput;
        String jediName;
        cout << "Welcome to the order, please enter your name, Jedi: " << endl;
        jediName.ReadFromConsole();
        gameMap.Render();
        while (gameRunning) {
            cout << "Enter Command: ";
            playerInput.ReadFromConsole();

            //make all input lower case to process easier
            playerInput.ToLower();

            //Add If logical statements here:
            if (playerInput.EqualTo("quit") || playerInput.EqualTo("run away") || playerInput.EqualTo("flee"))
            {
                gameRunning = false;
                cout << "You flee the galaxy far, far away. May the force be with you... always" << endl;
            }

            //logical movement scenarios
            if (playerInput.EqualTo("move north") || playerInput.EqualTo("move up")) {
                player.Move('n');
            }
            if (playerInput.EqualTo("move south") || playerInput.EqualTo("move down")) {
                player.Move('s');
            }
            if (playerInput.EqualTo("move west") || playerInput.EqualTo("move left")) {
                player.Move('w');
            }
            if (playerInput.EqualTo("move east") || playerInput.EqualTo("move right")) {
                player.Move('e');
            }
        }
    }
};

void ClearScreen() {
    // System-dependent command to clear the console
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}



int main()
{
    String nothing;
    // ASCII Art for "MALL"
    cout << R"(
 .      .     T h i s   i s   t h e   g a l a x y   o f   . . .             .
                     .              .       .                    .      .
.        .               .       .     .            .
   .           .        .                     .        .            .
             .               .    .          .              .   .         .
               _________________      ____         __________
 .       .    /                 |    /    \    .  |          \
     .       /    ______   _____| . /      \      |    ___    |     .     .
             \    \    |   |       /   /\   \     |   |___>   |
           .  \    \   |   |      /   /__\   \  . |         _/               .
 .     ________>    |  |   | .   /            \   |   |\    \_______    .
      |            /   |   |    /    ______    \  |   | \           |
      |___________/    |___|   /____/      \____\ |___|  \__________|    .
  .     ____    __  . _____   ____      .  __________   .  _________
       \    \  /  \  /    /  /    \       |          \    /         |      .
        \    \/    \/    /  /      \      |    ___    |  /    ______|  .
         \              /  /   /\   \ .   |   |___>   |  \    \
   .      \            /  /   /__\   \    |         _/.   \    \            +
           \    /\    /  /            \   |   |\    \______>    |   .
            \  /  \  /  /    ______    \  |   | \              /          .
 .       .   \/    \/  /____/      \____\ |___|  \____________/  LS
                               .                                        .
     .                           .         .               .                 .
                .                                   .            .                        
)" << endl;
    // Welcome Message
    cout << "Welcome to a galaxy far, far away, mortal." << endl;
    nothing.ReadFromConsole();
    ClearScreen();
    // Explaining instructions
    cout << "You are a new Jedi accepted into the order, your first job is to find a hollocron on the planet MALL" << endl;
    nothing.ReadFromConsole();

    cout << "But be warned, being a Jedi is no easy task!" << endl;
    nothing.ReadFromConsole();
    ClearScreen();
    


    Game game;
    game.Run();

    return 0;
}

