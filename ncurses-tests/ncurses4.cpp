#include <ncurses.h>

int main(int argc, char *argv[]) {
    // Boilerplate
    initscr();
    noecho();
    cbreak();

    if (!has_colors()) {
        printw("Terminal does not support colors.\n");
        getch();
        return -1;
    }

    // Initializing the color stuff
    start_color();

    // init_pair(id#, foreground-color, background-color);
    init_pair(1, COLOR_RED, COLOR_WHITE);

    // Sets the colors
    // attron(COLOR_PAIR(id#-from-above));
    attron(COLOR_PAIR(1));

    printw("Test");
    refresh();

    attroff(COLOR_PAIR(1));

    getch();

    endwin();

    return 0;
}
