#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <ncurses.h>

class Player {
    public:
        Player(WINDOW *);
        Player(WINDOW *, int, int, char);
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int  getmv();
        void display();

    protected:
        int rowLoc, colLoc, rowMax, colMax;
        char character;
        WINDOW *curwin;
};

#endif
