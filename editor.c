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
#include <stdio.h>
#include <string.h>
#include "editor.h"

void editorNewFile(struct *editor ed, const char* fn) {
  ed -> fn = malloc(strlen(fn) + 1); 
  strncpy(ed -> fn, fn, strlen(fn) + 1);
  ed -> contents = malloc(0);
  ed -> clength = 0; 
}

//@@@TODO: editorOpenFile() function.
