#include <cstdlib>
#include <iostream>
#include <random>
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

//Function for clearing screen allowing better UX:
void ClearScreen() {
    // System-dependent command to clear the console
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}



//Enums for class and spells
enum JediClass {
    JediSentinel,
    JediKnight,
    JediConsular,
    JediShadow
};

enum JediSpells {
    ForceShock,
    ForceWave,
    ForceBlast,
    ForceObliterate
};

enum Enemies {
    StormTrooper,
    ImperialWalker,
    BountyHunter,
    AssassinDroid,
    Sith,
    DarthVader
};

//function for better ux on jedi class to have enum displayed as string
String JediClassToString(JediClass jediClass) {
    switch (jediClass) {
    case JediSentinel:
        return "Jedi Sentinel";
    case JediKnight:
        return "Jedi Knight";
    case JediConsular:
        return "Jedi Consular";
    case JediShadow:
        return "Jedi Shadow";
    default:
        return "Unknown Class";
    }
}



// --- Room class
class Room {
public:
    string description;
    bool hasPlayer;
    Enemy* enemyInRoom; //trying this with a pointer to an enemy cause truck the other way
    //later will add more properties and methods here for items, enemy dark jedi etc.

    Room() : description(" - "), hasPlayer(false) {

    }

    void Render() const {
        if (hasPlayer)
        {
            cout << " P  ";
        }
        else {
            cout << description << " ";
        }
    }
};
// -- End Room class

class Enemy {
public:
    Enemies type;
    int xPosition;
    int yPosition;
    string representation;
    int health;
    int attack;

    Enemy(Enemies type, int x, int y) : type(type), xPosition(x), yPosition(y) {
        switch (type) {
        case StormTrooper: representation = " S ", health = 25, attack =25; break;
        case ImperialWalker: representation = " W ", health = 25, attack = 25; break;
        case BountyHunter: representation = " B ", health = 25, attack = 25; break;
        case AssassinDroid: representation = " D ", health = 25, attack = 25; break;
        case Sith: representation = " ! ", health = 25, attack = 25; break;
        case DarthVader: representation = " DV ", health = 25, attack = 25; break;
        default: representation = " ? "; // Fallback for unknown type
        }
    }
};
// --- Map class
class Map {
private:
public:
    vector<Enemy> enemies;
    static const int mapWidth = 10;
    static const int mapHeight = 10;
    Room rooms[mapWidth][mapHeight];//2D array of Room objects
    Map() {
        SetPlayerPosition(0, 0);
        PopulateEnemies();
    }; 

    void SetPlayerPosition(int x, int y) {

        //first a for loop to clear the current player pos. bool.
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                rooms[i][j].hasPlayer = false;
            }
        }

        //then we can set
        //avoid out of bounds measures within our 10 x 10 map
        if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight)
        {
            rooms[y][x].hasPlayer = true; // JFC y is rows and X IS FKIN COLUMNS DONT SPEND 2 HOURS ON THIS AGAIN !!
        }
    }

    void PopulateEnemies() {
        //try this to add 5 stormtroopers first
        for (int i = 0; i < 5; i++)
        {
            PlaceEnemy(StormTrooper);
        }
    }

    //This is copied from ChatGPT -- going tbh do not touch this lol
    void PlaceEnemy(Enemies type) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> disX(0, mapWidth - 1);
        uniform_int_distribution<> disY(0, mapHeight - 1);

        int x, y;
        do {
            x = disX(gen);
            y = disY(gen);
            // Repeat until an empty spot is found
        } while (!IsPositionEmpty(x, y));

        enemies.push_back(Enemy(type, x, y));
        rooms[y][x].description = enemies.back().representation; // Update room description to show enemy
    }

    bool IsPositionEmpty(int x, int y) {
        // Check if the position is empty (i.e., no other enemies and not the player's start position)
        if (x == 0 && y == 0) return false; // Assuming player starts at (0,0)
        for (const auto& enemy : enemies) {
            if (enemy.xPosition == x && enemy.yPosition == y) return false;
        }
        return true;
    }

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
    JediClass jediClass;
    int xPosition;
    int yPosition;
    int health;
    int mana; //will add functionality to this later
    int attack; // will add funcitonality to this later
    int defence; // will add functionality to this later

public:
    //Constructor to initialize attributes
    Player(String startName, JediClass startClass, int startX, int startY) : name(startName), jediClass(startClass), xPosition(startX), yPosition(startY) {
    
        // Set attributes based on JediClass
        switch (startClass) {
        case JediSentinel:
            health = 100; mana = 25; attack = 25; defence = 25;
            break;
        case JediKnight:
            health = 120; mana = 15; attack = 35; defence = 20;
            break;
        case JediConsular:
            health = 80; mana = 40; attack = 20; defence = 20;
            break;
        case JediShadow:
            health = 90; mana = 20; attack = 25; defence = 35;
            break;
        }
    };


    //Getters for player position within the map
    int GetX() const { return xPosition; }
    int GetY() const { return yPosition; }
    int GetHealth() const { return health; }
    int GetAttack() const { return attack; }
    int GetDefence() const { return defence; }
    int GetMana() const { return mana; }

    //Method to move the player
    void Move(char direction) {
        int newX = xPosition, newY = yPosition;

        switch (direction) {
        case 'n': newY--; break; // Assuming the top of the map is "north"
        case 's': newY++; break;
        case 'e': newX++; break;
        case 'w': newX--; break;
        default: cout << "Invalid direction." << endl; return;
        }

        //Check boundary here:
        if (newX < 0 || newX >= Map::mapWidth || newY < 0 || newY >= Map::mapHeight) 
        {
            cout << "Invalid move: You cannot leave MALL that easily" << endl;
        }
        else {
            xPosition = newX;
            yPosition = newY;
        }
    }
};


class Item;


class Game {

private:
    Map gameMap; // add this as a member of the game class
    Player player; // init the player in game constructor
public:
    Game() : player(" ",JediSentinel, 0, 0) {
        //Map gets initialized here
    }

    void Run() {
        bool gameRunning = true;
        String playerInput;
        String jediName;
        String classChoice;

        //during run player enters his name
        cout << "Welcome to the order, please enter your name, Jedi: " << endl;
        jediName.ReadFromConsole();

        //Player then selects his class
        cout << "Select your class Jedi:" << endl;
        cout << "1. Jedi Sentinel" << endl;
        cout << "2. Jedi Knight" << endl;
        cout << "3. Jedi Consular" << endl;
        cout << "4. Jedi Shadow" << endl;
        classChoice.ReadFromConsole();
        classChoice.ToLower();

        //logical if statement to determine Jedi class
        JediClass chosenClass;
        if (classChoice.EqualTo("jedi sentinel") || classChoice.EqualTo("1")) {
            chosenClass = JediSentinel;
        }
        else if (classChoice.EqualTo("jedi knight") || classChoice.EqualTo("2")) {
            chosenClass = JediKnight;
        }
        else if (classChoice.EqualTo("jedi consular") || classChoice.EqualTo("3")) {
            chosenClass = JediConsular;
        }
        else if (classChoice.EqualTo("jedi shadow") || classChoice.EqualTo("4")) {
            chosenClass = JediShadow;
        }
        else {
            cout << "Invalid choice, defaulting to Jedi Sentinel." << endl;
            chosenClass = JediSentinel;
        }

        //then set the name and player class here before we run our game loop...
        player = Player(jediName, chosenClass, 0, 0);

        //we render map before loop we must change this later to have it 
        // inside the loop and refresh every instance
        int displayHealth = player.GetHealth();
        int displayAttack = player.GetAttack();
        int displayDefence = player.GetDefence();
        int displayMana = player.GetMana();

        while (gameRunning) {
            // clear the screen for better ux
            ClearScreen();
            gameMap.SetPlayerPosition(player.GetX(), player.GetY());
            gameMap.Render();
            cout << "Make your move, " << JediClassToString(chosenClass) << ", " << jediName << "!" << endl;
            cout << "Your current health is: " << displayHealth << endl;
            cout << "Your current health is: " << displayAttack << endl;
            cout << "Your current health is: " << displayDefence << endl;
            cout << "Your current health is: " << displayMana << endl;
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

