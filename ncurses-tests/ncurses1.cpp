#include <iostream>
#include <ncurses.h>

int main (int argc, char *argv[]) {
    initscr();

    printw("Enter something: ");
    int test = getch();
    printw("\n");

    printw("You entered: %c\n", test);

    getch();

    endwin();
    return 0;
}
