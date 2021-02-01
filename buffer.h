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

#include <stdlib.h>

#ifndef BUFFER_H
#define BUFFER_H

static const unsigned int BUFFER_SIZE = 1024;

struct buffer 
{ /*char sequence to render the screen*/
  char* contents;
  int   length;
  int   capacity;
};

struct  buffer* bufferCreate();
void    bufferDel(struct buffer* bf);
void    bufferApp(struct buffer* bf, const char* file, size_t length);  /*buffer append file writing bytes length*/
int     bufferAppf(struct buffer* bf, const char* file, ...);     /*buffer appendf appends file but with formatted text.*/
void    bufferWrite(struct buffer* bf);

#endif
