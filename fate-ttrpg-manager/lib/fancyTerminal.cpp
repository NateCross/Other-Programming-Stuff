#include <iostream>
#include <ostream>
#include "fancyTerminal.hpp"

const void fancy_moveCursor(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H" << std::flush;
}

const void fancy_clearScreen() {
    std::cout << "\x1B[2J" << std::flush;
}

const void fancy_colorNormal() { std::cout << "\x1B[0m" << std::flush; }
const void fancy_colorRed() { std::cout << "\x1B[1;31m" << std::flush; }
const void fancy_colorGreen() { std::cout << "\x1B[1;32m" << std::flush; }
const void fancy_colorYellow() { std::cout << "\x1B[1;33m" << std::flush; }
const void fancy_colorBlue() { std::cout << "\x1B[1;34m" << std::flush; }
const void fancy_colorMagenta() { std::cout << "\x1B[1;35m" << std::flush; }
const void fancy_colorCyan() { std::cout << "\x1B[1;36m" << std::flush; }
const void fancy_colorWhite() { std::cout << "\x1B[1;37m" << std::flush; }

