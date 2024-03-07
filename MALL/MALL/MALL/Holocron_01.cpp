#include "Holocron_01.h"
#include <iostream>



void Holocron_01::Use(Player& player)  {
    String nothing;
    std::cout << "Well done, Jedi, you have found the Holocron and earned your rank amongst the Jedi Masters" << std::endl;
    // Assuming String has a method ReadFromConsole. Otherwise, adjust accordingly.
    nothing.ReadFromConsole();
    std::exit(0); // Ends game after finding the holocron
};
