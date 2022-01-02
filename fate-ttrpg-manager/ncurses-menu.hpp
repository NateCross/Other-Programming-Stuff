#ifndef _NCURSES_MENU_H_
#define _NCURSES_MENU_H_

#include <iostream>
#include <ncurses.h>

static const unsigned int CHOICES_MAX = 50;

class Menu {
    public:
        Menu(WINDOW *);
        Menu(WINDOW *, const std::string []);

        void setChoice(const std::string&, const int&);
        int  getCurrChoice();
        // void incrementChoice();
        // void decrementChoice();
        void mvUp();
        void mvDown();
        void display();
        int  getUserInput();


    protected:
        std::string  _choices[CHOICES_MAX];
        unsigned int _currentChoice;
        unsigned int _maxChoices;
        int          _winRowMax;
        int          _winColMax;
        WINDOW *     _currentWin;
};

#endif
