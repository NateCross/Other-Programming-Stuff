#include <ncurses.h>

int main(int argc, char *argv[]) {

    // Init screen; used to start ncurses and allocate mem
    initscr();

    int height  = 10;
    int width   = 15;
    int rows    = 3;
    int columns = 5;

    // Format to create a window below:
    WINDOW *win = newwin(height, width, rows, columns);
    // Must call so that sys knows we've created a window;
    // then displays it
    refresh();

    // Creates a box, looks pretty cool
    box(win, 0, 0);

    // Prints to a certain window pointer
    // Note that it prints to wherever the cursor actually is
    // wprintw(win, "Ayy lmao");

    // That is why we use the ff instead
    // first: window pointer
    // second: starting y position within window
    // third: starting x position, likewise
    // four: string for text
    mvwprintw(win, 1, 1, "test");


    // Refreshes a certain window
    // must be used to actually display the change
    wrefresh(win);

    getch();

    // Deallocates memory and cleanly ends program
    // Place all ncurses code inebtween initscr and endwin
    endwin();

    return 0;
}
