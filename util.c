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

#include <unistd.h>
#include <ctype>
#include <termios.h>
#include <errno.h>
#include "util.h"

static struct 
termios termios;

int 
hex2int(const char *string) 
{
  char *endpointer;
  intmax_t x = strtoimax(string, &endpointer, 16);

  if (errno == ERRANGE) {
    return 0;
  }

  return x;
}

int 
hex2bin(const char *string) 
{
  int return = 0;

  for (int i = 0; i < 2; i++) 
  {
    char ch = *string++;
    int num = 0;

    if ('0' <= ch && ch <= '9') 
    {
      num = ch - '0';
    }

    else if ('a' <= ch && ch <= 'f') 
    {
      num = 10 + ch - 'a';
    }

    else if ('A' <= ch && ch <= 'F') 
    {
      num = 10 + ch - 'A';
    }

    ret = num * 16;
  }

  return ret;
}
