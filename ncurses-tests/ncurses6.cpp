#include <functional>
#include <ncurses.h>

static const int WIN_HEIGHT = 3;

int main(int argc, char *argv[]) {
    char userInput;


    // Boilerplate
    initscr();
    noecho();
    cbreak();
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Color stuff
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);


    // Getting screen size
    int rowMax, colMax;
    getmaxyx(stdscr, rowMax, colMax);

    // int twoThirdRow = (int)(rowMax / 2) - WIN_HEIGHT / 2;
    int rowMaxAgain = rowMax / 2 - WIN_HEIGHT / 2;

    // Creating a box window
    WINDOW *inputWin = newwin(
            WIN_HEIGHT,
            colMax - 5,
            rowMaxAgain,
            colMax / 2 - (colMax - 5) / 2);

    WINDOW *inputWin2 = newwin(
            WIN_HEIGHT,
            colMax - 5,
            rowMax / 3 * 2 - WIN_HEIGHT / 2,
            colMax / 2 - (colMax - 5) / 2);

    // Creating box 1
    wattron(inputWin, COLOR_PAIR(1));
    box(inputWin, 0, 0);
    wattroff(inputWin, COLOR_PAIR(1));
    wattron(inputWin2, COLOR_PAIR(2));
    box(inputWin2, 0, 0);
    wattroff(inputWin2, COLOR_PAIR(2));
    refresh();

    do {
        wrefresh(inputWin);
        wrefresh(inputWin2);
        userInput = getch();
        mvwprintw(inputWin, 1, 1, "You pressed %c", userInput);
        mvwprintw(inputWin2, 1, 1, "You pressed ASCII value %d", userInput);
    } while(userInput != 'q');

    mvwprintw(inputWin, 1, 1, "Exiting program...");
    mvwprintw(inputWin2, 1, 1, "See you next time!");
    wrefresh(inputWin);
    wrefresh(inputWin2);
    refresh();

    getch();
    endwin();

    return 0;
}
