#include <ncurses.h>
#include <string>

int main(int argc, char *argv[]) {
    // Usual Boilerplate
    initscr();
    noecho();
    cbreak();

    start_color();
    init_pair(1, COLOR_RED, COLOR_YELLOW);

    int y, x, rowBeg, colBeg, rowMax, colMax;

    // stdscr is the, well, actual screen
    // it changes the values of y and x to the current cursor pos
    getyx(stdscr, y, x);

    getbegyx(stdscr, rowBeg, colBeg);

    getmaxyx(stdscr, rowMax, colMax);

    attron(COLOR_PAIR(1));
    printw("%d %d %d %d %d %d", y, x, rowBeg, colBeg, rowMax, colMax);
    refresh();
    attroff(COLOR_PAIR(1));

    // to create a centered window, you must do max/2 for row and col,
    // then, subtract it by the dimensions given to the window
    WINDOW *win = newwin(10, 10, rowMax/2 - 10/2, colMax/2 - 10/2);
    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Test");
    wrefresh(win);

    getch();
    endwin();

    return 0;
}
