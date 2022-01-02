// Basic Menu System

#include <ncurses.h>
#include <string>

int main(int argc, char *argv[]) {
    // Boilerplate
    initscr();
    noecho();
    cbreak();

    // Getting Screen Size
    int rowMax, colMax;
    getmaxyx(stdscr, rowMax, colMax);

    // Creating a window for input
    WINDOW *menuwin = newwin(6, colMax-12, rowMax-8, 5);
    box(menuwin, 0, 0);
    refresh();      // Don't forget to refresh after changing window state
    wrefresh(menuwin);

    // Makes it so we can use arrow keys
    keypad(menuwin, true);

    std::string choices[] = {
        "Walk",
        "Jog",
        "Run"
    };
    int choice;
    int highlight = 0;

    while (true) {
        for (int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE); // Reverses fg and bg colors
                // mvwprintw(menuwin, i+1, 1, ">> ");
            mvwprintw(menuwin, i+1, 4, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
            // wrefresh(menuwin);
        }
        choice = wgetch(menuwin);

        switch (choice) {
            case 'k':
                // NOTE: You cannot oneliner with the modulo here
                // Modulo on negative numbers produces a negative number
                // highlight = (highlight - 1) % 4;
                highlight--;
                if (highlight == -1)
                    highlight = 2;
                break;
            case 'j':
                highlight++;
                if (highlight == 3)
                    highlight = 0;
                break;
            default:
                break;
        }
        if(choice == 10) // Enter was pressed
            break;
    }
    printw("Your choice is: %s", choices[highlight].c_str());
    refresh();

    getch();
    endwin();
}
