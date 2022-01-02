#include <ncurses.h>

int main(int argc, char *argv[]) {
    initscr();

    cbreak();    // Makes ctrl+c exit out of ncurses, DEFAULT
    // raw();    // Takes all input as raw input; no ctrl+c to exit
    noecho();    // Doesn't display input

    int height = 10;
    int width  = 10;
    int row    = 5;
    int column = 5;

    WINDOW *win = newwin(height, width, row, column);
    refresh();

    box(win, '*', 0); // The int parameters show the char which makes
                      // up the border of the box
                      // Can use char, which automatically gets casted

    // To better customize the borders of a window
    // Those all take ints, and therefore chars as well
    // wborder(win, left, right, top, bottom, top-left, top-right, bottom-left, bottom-right);

    wrefresh(win);

    getch();

    endwin();

    return 0;
}
