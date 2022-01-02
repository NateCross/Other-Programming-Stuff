// This is a simple menu system for ncurses
// it is designed to be as portable as possible
// only handling I/O; not much else special

#include "ncurses-menu.hpp"
#include <curses.h>

Menu::Menu(WINDOW *win) {
    _currentWin    = win;
    _currentChoice = 0;
    getmaxyx(_currentWin, _winRowMax, _winColMax);
    for (int i = 0; i < CHOICES_MAX; i++)
        setChoice("", i);
    _maxChoices    = 0;
}

Menu::Menu (WINDOW *win, const std::string choices[])
    : Menu(win) {
        for (int i = 0; i < CHOICES_MAX; i++)
            setChoice(choices[i], i);
    }

void Menu::setChoice(const std::string& choice, const int& pos) {
    if (_choices[pos] == "")
        ++_maxChoices;
    _choices[pos] = choice;
}

int Menu::getCurrChoice() { return _currentChoice; }

void Menu::mvUp() { getCurrChoice() > 0 ? --_currentChoice : _currentChoice;  }

void Menu::mvDown() { getCurrChoice() < _maxChoices ? ++_currentChoice : _currentChoice;  }

void Menu::display() {
    for (int i = 0; i < _maxChoices; i++) {
        if (i == _currentChoice)
            mvwprintw(_currentWin, i + 1, 1, ">> ");
        mvwprintw(_currentWin, i + 1, 5, _choices[i].c_str());
    }
}

int Menu::getUserInput() {
    int input = wgetch(_currentWin);
    mvwprintw(_currentWin, getCurrChoice() + 1, 1, "   ");
    switch (input) {
        case 'j':
            mvDown();
            break;
        case 'k':
            mvUp();
            break;
        default:
            break;
    }
    return input;
}
