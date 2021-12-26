// Based on
// https://gitlab.com/greggink/youtube_episode_control_terminal/-/blob/master/tc.h

#ifndef FANCY_TERM_H
#define FANCY_TERM_H

const void fancy_moveCursor(const int&, const int&);

const void fancy_clearScreen();

const void fancy_colorNormal();
const void fancy_colorRed();
const void fancy_colorGreen();
const void fancy_colorYellow();
const void fancy_colorBlue();
const void fancy_colorMagenta();
const void fancy_colorCyan();
const void fancy_colorWhite();

#endif
