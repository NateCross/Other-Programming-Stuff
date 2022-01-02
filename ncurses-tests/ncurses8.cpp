#include "ncurses8.hpp"

int main() {
    // Boilerplate
    initscr();
    noecho();
    cbreak();
    curs_set(0); // Hides cursor

    // Setting up window
    int termRowMax, termColMax;
    getmaxyx(stdscr, termRowMax, termColMax);
    printw("RowMax: %d ColMax: %d\n", termRowMax, termColMax);
    WINDOW *boxWin = newwin(10, 10, termRowMax / 2 - 10 / 2, termColMax / 2 - 10 / 2);
    box(boxWin, 0, 0);
    refresh();
    wrefresh(boxWin);

    Player pl(boxWin, 1, 1, '@');

    // Main loop
    do {
        pl.display();
        wrefresh(boxWin);
    } while(pl.getmv() != 'x');

    printw("Press any key to continue.");

    getch();
    delwin(boxWin);     // Must deallocate before exiting
    endwin();

    return 0;
}

Player::Player(WINDOW *win) {
    curwin = win;
}

Player::Player(WINDOW *win, int rowStart, int colStart, char ch) 
    : Player(win) {
        rowLoc    = rowStart;
        colLoc    = colStart;
        character = ch;
        getmaxyx(curwin, rowMax, colMax);
        keypad(curwin, true);
    }

void Player::mvup() { rowLoc > 1 ? --rowLoc : rowLoc; }

void Player::mvdown() { rowLoc < rowMax - 2 ? ++rowLoc : rowLoc; }

void Player::mvleft() { colLoc > 1 ? --colLoc : colLoc; }

void Player::mvright() { colLoc < colMax - 2 ? ++colLoc : colLoc; }

int Player::getmv() {
    int choice = wgetch(curwin);
    mvwaddch(curwin, rowLoc, colLoc, ' '); // Removes leftover character
    switch (choice) {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display() {
    mvwaddch(curwin, rowLoc, colLoc, character);
}
