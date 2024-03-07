#pragma once

#include "Game.h"
#include "String.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Function for clearing screen allowing better UX:
//void ClearScreen() {
//    // System-dependent command to clear the console
//#ifdef _WIN32
//    system("CLS");
//#else
//    system("clear");
//#endif
//}



int main()
{
    Game game;
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
    game.ClearScreen();

    // Explaining instructions
    cout << "You are a new Jedi accepted into the order, your first job is to find a hollocron on the planet MALL" << endl;
    nothing.ReadFromConsole();

    game.Run();

    return 0;
}

