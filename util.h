/*
 * Copyright (C) 2021 Biel A. P. - 0xbiel <biel@ugly.cat>
 * Author: Biel A. P. - 0xbiel <biel@ugly.cat>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <termios.h>

enum keys 
{
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

enum errors 
{
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
