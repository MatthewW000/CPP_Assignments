
#include <iostream>
#include <vector>
#include "String.h"
using namespace std;

class Room;
class Item;
class Player;
class Enemy;

class Game {
public:
    Game() {

    }

    void Run() {
        bool gameRunning = true;
        String playerInput;

    }
};

int main()
{
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

    Game game;
    game.Run();
}

