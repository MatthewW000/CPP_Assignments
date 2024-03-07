#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
#include "String.h"
#include <windows.h>
#include <map>
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

enum ItemTypes {
    Hollocron,
    HealthPotion,
    ManaPotion,
    Unknown
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


class Enemy {
public:
    int xPosition;
    int yPosition;
    char representation = 'S'; // Representation for Stormtrooper

    Enemy(int x, int y) : xPosition(x), yPosition(y) {}
};

// --- Room class
class Room {
public:
    string description;
    bool hasPlayer;
    bool hasEnemy; //trying this with a pointer to an enemy cause truck the other way
    //later will add more properties and methods here for items, enemy dark jedi etc.


    Room() : description(" - "), hasPlayer(false), hasEnemy(false) {

    }

    ~Room() {};

    void Render() const {
        if (hasPlayer) {
            cout << " P ";
        }
        else if (hasEnemy) {
            cout << " S "; // Represent stormtrooper
        }
        else {
            cout << description;
        }
    }
};
// -- End Room class

// --- Map class
class Map {
public:
    vector<Enemy> enemies;
    static const int mapWidth = 10;
    static const int mapHeight = 10;
    Room rooms[mapWidth][mapHeight];//2D array of Room objects
    Map() {
        SetPlayerPosition(0, 0);
        PopulateEnemies();
    }; 

    ~Map() {};

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
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> disX(0, mapWidth - 1);
        uniform_int_distribution<> disY(0, mapHeight - 1);

        for (int i = 0; i < 5; i++) {
            int x, y;
            do {
                x = disX(gen);
                y = disY(gen);
            } while (!IsPositionEmpty(x, y));

            // Note: Since you're simplifying, you don't need to create Enemy instances here
            // Just mark the room as having an enemy
            rooms[y][x].hasEnemy = true;
        }
    }


    // Legacy code is here dont uncomment this dumb shizzle
    //void PopulateEnemies() {
    //    //try this to add 5 stormtroopers first
    //    for (int i = 0; i < 5; i++)
    //    {
    //        PlaceEnemy( 25, 25);
    //    }
    //}

    ////This is copied from ChatGPT -- going tbh do not touch this lol
    //void PlaceEnemy( int health, int attack) {
    //    //random position generate logic
    //    random_device rd;
    //    mt19937 gen(rd());
    //    uniform_int_distribution<> disX(0, mapWidth - 1);
    //    uniform_int_distribution<> disY(0, mapHeight - 1);

    //    int x, y;
    //    do {
    //        x = disX(gen);
    //        y = disY(gen);
    //        // Repeat until an empty spot is found
    //    } while (!IsPositionEmpty(x, y));

    //    // Create an Enemy with all necessary parameters and add it to the vector
    //    enemies.emplace_back(x, y, health, attack);
    //    rooms[y][x].hasEnemy = true;
    //}

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

public:
    //must make health public to be accessible for battle
    int health;
    int mana; //will add functionality to this later
    int attack; // will add funcitonality to this later
    int defence; // will add functionality to this later
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

    Player() {};
    ~Player() {};


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


class Item {};


class Game {

private:
    Map gameMap; // add this as a member of the game class
    Player player; // init the player in game constructor
public:
    Game() : player(" ",JediSentinel, 0, 0) {
        //Map gets initialized here
    }

    ~Game() {};

    void Battle(Player& player, Room& room) {
        if (room.hasEnemy) {
            // Simplified battle logic
            cout << "You've encountered a Stormtrooper! Fight (f) or flee (r)? "<< endl;
            //ascii art for stormtrooper
            cout << R"(                            ,ooo888888888888888oooo,
                          o8888YYYYYY77iiiiooo8888888o
                         8888YYYY77iiYY8888888888888888
                        [88YYY77iiY88888888888888888888]
                        88YY7iYY888888888888888888888888
                       [88YYi 88888888888888888888888888]
                       i88Yo8888888888888888888888888888i
                       i]        ^^^88888888^^^     o  [i
                      oi8  i           o8o          i  8io
                    ,77788o ^^  ,oooo8888888ooo,   ^ o88777,
                    7777788888888888888888888888888888877777
                     77777888888888888888888888888888877777
                      77777788888888^7777777^8888888777777
       ,oooo888 ooo   88888778888^7777ooooo7777^8887788888        ,o88^^^^888oo
    o8888777788[];78 88888888888888888888888888888888888887 7;8^ 888888888oo^88
   o888888iii788 ]; o 78888887788788888^;;^888878877888887 o7;[]88888888888888o
   88888877 ii78[]8;7o 7888878^ ^8788^;;;;;;^878^ ^878877 o7;8 ]878888888888888
  [88888888887888 87;7oo 777888o8888^;ii;;ii;^888o87777 oo7;7[]8778888888888888
  88888888888888[]87;777oooooooooooooo888888oooooooooooo77;78]88877i78888888888
 o88888888888888 877;7877788777iiiiiii;;;;;iiiiiiiii77877i;78] 88877i;788888888
 88^;iiii^88888 o87;78888888888888888888888888888888888887;778] 88877ii;7788888
;;;iiiii7iiii^  87;;888888888888888888888888888888888888887;778] 888777ii;78888
;iiiii7iiiii7iiii77;i88888888888888888888i7888888888888888877;77i 888877777ii78
iiiiiiiiiii7iiii7iii;;;i7778888888888888ii7788888888888777i;;;;iiii 88888888888
i;iiiiiiiiiiii7iiiiiiiiiiiiiiiiiiiiiiiiii8877iiiiiiiiiiiiiiiiiii877   88888
ii;;iiiiiiiiiiiiii;;;ii^^^;;;ii77777788888888888887777iii;;  77777           78
77iii;;iiiiiiiiii;;;ii;;;;;;;;;^^^^8888888888888888888777ii;;  ii7         ;i78
^ii;8iiiiiiii ';;;;ii;;;;;;;;;;;;;;;;;;^^oo ooooo^^^88888888;;i7          7;788
o ^;;^^88888^     'i;;;;;;;;;;;;;;;;;;;;;;;;;;;^^^88oo^^^^888ii7         7;i788
88ooooooooo         ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 788oo^;;          7;i888
887ii8788888      ;;;;;;;ii;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;^87           7;788
887i8788888^     ;;;;;;;ii;;;;;;;oo;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,      ;;888
87787888888     ;;;;;;;ii;;;;;;;888888oo;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,;i788
87i8788888^       ';;;ii;;;;;;;8888878777ii8ooo;;;;;;;;;;;;;;;;;;;;;;;;;;i788 7
77i8788888           ioo;;;;;;oo^^ooooo ^7i88^ooooo;;;;;;;;;;;;;;;;;;;;i7888 78
7i87788888o         7;ii788887i7;7;788888ooooo7888888ooo;;;;;;;;;;;;;;oo ^^^ 78
i; 7888888^      8888^o;ii778877;7;7888887;;7;7788878;878;;    ;;;;;;;i78888o ^
i8 788888       [88888^^ ooo ^^^^^;;77888^^^^;;7787^^^^ ^^;;;;  iiii;i78888888
^8 7888^        [87888 87 ^877i;i8ooooooo8778oooooo888877ii; iiiiiiii788888888
  ^^^          [7i888 87;; ^8i;;i7888888888888888887888888   i7iiiiiii88888^^
               87;88 o87;;;;o 87i;;;78888788888888888888^^ o 8ii7iiiiii;;
               87;i8 877;77888o ^877;;;i7888888888888^^ 7888 78iii7iii7iiii
               ^87; 877;778888887o 877;;88888888888^ 7ii7888 788oiiiiiiiii
                 ^ 877;7 7888888887 877i;;8888887ii 87i78888 7888888888
                  [87;;7 78888888887 87i;;888887i  87ii78888 7888888888]
                  877;7 7788888888887 887i;887i^  87ii788888 78888888888
                  87;i8 788888888888887 887ii;;^ 87ii7888888 78888888888
                 [87;i8 7888888888888887 ^^^^   87ii77888888 78888888888
                 87;;78 7888888888888887ii      87i78888888 778888888888
                 87;788 7888888888888887i]      87i78888888 788888888888
                [87;88 778888888888888887       7ii78888888 788888888888
                87;;88 78888888888888887]       ii778888888 78888888888]
                7;;788 7888888888888888]        i7888888888 78888888888'
                7;;788 7888888888888888         'i788888888 78888888888
                7;i788 788888888888888]          788888888 77888888888]
                '7;788 778888888888888]         [788888888 78888888888'
                ';77888 78888888888888          8888888888 7888888888]
                 778888 78888888888888          8888888888 7888888888]
                  78888 7888888888888]         [8888888888 7888888888
                   7888 788888888888]          88888888888 788888888]
                    778 78888888888]           ]888888888 778888888]
                    oooooo ^88888^              ^88888^^^^^^^^8888]
                   87;78888ooooooo8o            ,oooooo oo888oooooo
                   [877;i77888888888]          [;78887i8888878i7888;
                    ^877;;ii7888ii788          ;i777;7788887787;778;
                     ^87777;;;iiii777          ;77^^^^^^^^^^^^^^^^;;
                        ^^^^^^^^^ii7]           ^ o88888888877iiioo
                           77777o               [88777777iiiiii;;778
                            77777iii            8877iiiii;;;77888888]
                            77iiii;8           [77ii;778 788888888888
                            7iii;;88           iii;78888 778888888888
                           77i;78888]          ;;;;i88888 78888888888
                          ,7;78888888          [;;i788888 7888888888]
                          i;788888888           ;i7888888 7888888888
                          ;788888888]           i77888888 788888888]
                          ';88888888'           [77888888 788888888]
                           [[8ooo88]             78888888 788888888
                            [88888]              78888888 788888888
                              ^^^                [7888888 77888888]
                                                  88888888 7888887
                                                  77888888 7888887
                                                   ;i88888 788888i
                                                  ,;;78888 788877i7
                                                 ,7;;i;777777i7i;;7
                                                 87778^^^ ^^^^87778
                                                  ^^^^ o777777o ^^^
                                                  o77777iiiiii7777o
                                                 7777iiii88888iii777
                                                ;;;i7778888888877ii;;
                   Imperial Stormtrooper       [i77888888^^^^8888877i]
                  (Standard Shock Trooper)     77888^oooo8888oooo^8887]
                                              [788888888888888888888888]
                                              88888888888888888888888888
                                              ]8888888^iiiiiiiii^888888]
                       Bob VanderClay           iiiiiiiiiiiiiiiiiiiiii
                                                    ^^^^^^^^^^^^^)" << endl;
            char action;
            cin >> action;

            if (action == 'f') {
                // For simplicity, let's say you always win and remove the enemy
                cout << "You've defeated the Stormtrooper!" << endl;
                room.hasEnemy = false; // Enemy defeated
                // You might want to update the player's state (health, experience, etc.) here
            }
            else {
                cout << "You fled!" << endl;
                // Handle fleeing - maybe move back or lose some health
            }
        }
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

            // Check for a battle phase
            Room& currentRoom = gameMap.rooms[player.GetY()][player.GetX()];
            Battle(player, currentRoom);

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

    Game game;
    game.Run();

    return 0;
}

