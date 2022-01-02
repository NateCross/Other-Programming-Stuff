// Quick Notes
// - Must always close any fancy_colorX with fancy_colorNormal
//   - This is because it uses UNIX terminal jank to display colors
//   - so that this can work cross platform

#include <cstdio>
#include <iostream>
#include <string>
#include "character.hpp"
#include "ncurses-menu.hpp"

const void pressEnter() {
    printw("Press Enter to continue.");
    getch();
}

std::string createAspect() {
    std::string temp;
    std::cout << "Enter aspect: ";
    getline(std::cin, temp);
    return temp;
}

int createPos() {
    std::string temp;
    std::cout << "Enter position: ";
    getline(std::cin, temp);
    return std::stoi(temp);
}

void flushCin() {
    std::cin.clear();
    std::cin.ignore();
}

int main(int argc, char *argv[]) {
    Character   player;
    char        choice;
    std::string inputAspect;
    int         inputPos;

    do {
        fancy_clearScreen();

        std::cout << "Name: ";
        fancy_colorBlue();
        std::cout << player.getName() << "\n";
        fancy_colorNormal();

        std::cout << "Fate Points: ";
        fancy_colorGreen();
        std::cout << player.getFatePts() << "\n\n";
        fancy_colorNormal();

        std::cout << "Aspects\n";
        fancy_colorCyan();
        player.displayAllAspects();
        fancy_colorNormal();

        std::cout << "\n\n"
                  << "q. Change name\n"
                  << "1. Add new aspect\n"
                  << "2. Change existing aspect\n"
                  << "3. Delete aspect\n"
                  << "4. Add Fate Point\n"
                  << "5. Remove Fate Point\n"
                  << "0. Exit\n";

        std::cout << "\n\n" << "Enter choice: ";
        std::cin >> choice;
        flushCin();
        // std::cin.get(choice);

        switch(choice) {
            case 'q':
                std::cout << "Enter name: ";
                getline(std::cin, inputAspect);
                player.setName(inputAspect);
                break;
            case '1':
                inputAspect = createAspect();
                player.addAspect(inputAspect);
                break;
            case '2':
                inputAspect = createAspect();
                inputPos    = createPos();
                player.setAspect(inputAspect, inputPos);
                break;
            case '0':
                break;
            default:
                std::cout << "ERROR: Incorrect input.\n";
                break;
        }
        pressEnter();

    } while(choice != '0');

    // int test = 5;
    // test += 2;
    // std::cout << test << "\n";

    // Character player("Nice", 4);
    // std::cout << "Number of aspects: " << player.getAspectNum() << "\n";
    // std::cout << player.getFatePts() << "\n";
    // player.displayAllAspects();
    // player.setAspect("Peed in the shower", 2);
    // player.setAspect("Expert at backflipping when nobody's around", 4);
    // player.setAspect("Ayy lmao", 5);
    // player.addAspect("heh");
    // player.displayAllAspects();
    // std::cout << "Number of aspects: " << player.getAspectNum() << "\n";

    return 0;
}

