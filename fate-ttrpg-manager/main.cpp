#include <iostream>
#include "character.hpp"
#include "lib/fancyTerminal.hpp"

int main(int argc, char *argv[]) {
    fancy_clearScreen();
    fancy_colorCyan();
    std::cout << "Test\n";
    fancy_colorNormal();
    return 0;
}

