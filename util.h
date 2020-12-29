#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <termios.h>

enum keys {
  ESC         =   0x1b,
  RETURN      =   0x0d,
  BACKSPACE   =   0x7f, 
  CTRL_U      =   0x15,
  CTRL_S      =   0x13,
  CTRL_R      =   0x12,
  CTRL_Q      =   0x11,
  CTRL_H      =   0x08,
  CTRL_D      =   0x04,
  NONE        =   0,
  UP          =   1000,
  DOWN,
  RIGHT,
  LEFT,
  HOME,
  END,
  DEL,
  PGUP,
  PGDOWN,
};

enum errors {
  SUCCESS,
  INCBACKSLASH, /*incomplete backslash*/
  INCHEX,       /*incomplete hex*/
  INVHEX,       /*invalid hex*/
  INVESC,       /*invalid escape*/
};

void saveState();
void restoreState();
void enableRaw();
void disableRaw();
void readKey();
void clear();
void getWinSize(int* rows, int* cols);
int  hexToBin(const char* str);
bool isHex(const char* str);
bool positiveNum(const char* str);
int  hexToInt(const char* str);
int  adj(int i, int min, int max);
int  strToInt(const char* str, int min, int max, int dflt);

#endif
