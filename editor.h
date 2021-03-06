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

#ifndef EDITOR_H
#define EDITOR_H
#define INPUTSIZE 80

#include <stdbool.h>
#include "buffer.h"

enum editmode 
{
  APPEND      =     0x001,    /*append text after cursor.*/
  APPENDCURR  =     0x002,    /*append text after current cursor position.*/
  NORMAL      =     0x004,    /*normal mode...*/
  INSERT      =     0x008,    /*insert mode...*/
  INSERTLIT   =     0x010,    /*insert literal typed stuff.*/
  REPLACE     =     0x020,    /*replace mode...*/
  CMD         =     0x040,    /*command mode.*/
  SEARCH      =     0x100,    /*searh mode like ctrl+f on browsers.*/
};

enum searchdir 
{
  FWD,
  BCKWD,
};

enum status 
{
  INFO,     /*blue bg.*/
  ERROR,    /*red bg.*/
  WARNING,  /*yellow bg.*/
};

struct editor 
{
  int           bpl;          /*bytes per line.*/
  int           bpg;          /*bytes per group.*/
  int           cx;           /*cursor x.*/
  int           cy;           /*cursor y.*/
  int           line;
  int           rows;
  int           cols;
  int           mode;
  bool          bm;           /*buffer modified?*/
  char*         contents;     /*file contents.*/
  unsigned int  clength;      /*content length.*/
  char*         fn;           /*filename*/
  enum          status stts;  /*status*/
  char          sttmsg[120];  /*status message*/
  struct        act* undo;
  char          ib[INPUTSIZE];
  int           ibindex;
  char          srch[INPUTSIZE];
};

struct  editor* editorInit();
void    editorCursorPos(struct editor* ed, int pos, int* x, int* y);
void    editorDelAtCursor(struct editor* ed);
void    editorDelOffset(struct editor* ed, unsigned int offset);
void    editorFree(struct editor* ed);
void    editorIncByte(struct editor* ed, int amount);
void    editorInsByte(struct editor* ed, char x, bool after);
void    editorInsByteOff(struct editor* ed, unsigned int position, char x, bool after);
void    editorMoveCursor(struct editor* ed, int dir, int amount);
void    editorOffCursor(struct editor* ed);
void    editorNewFile(struct editor* ed, const char* fn);
void    editorOpenFile(struct editor* ed, const char* fn);
void    editorCommand(struct editor* ed, const char* cmd);
void    editorSearch(struct editor* ed, const char* search, enum searchdir dir );
int     editorSearchStr(const char* input, struct buffer* str, const char** err);
void    editorKeyPress(struct editor* ed);
int     editorHex(struct editor* ed, char* out);
int     editorStr(struct editor* ed, char* st, int length);
int     edtiorAscii(struct editor* ed, int rownum, unsigned int startoff, struct buffer* bf);
void    editorRender(struct editor* ed, struct buffer* bf);
void    editorHelp(struct editor* ed);
void    editorInfo(struct editor* ed, struct buffer* bf);
void    editorStatus(struct editor* ed, struct buffer* bf);
void    editorRefresh(struct editor* ed);
void    editorReplace(struct editor* ed, char x);
void    editorReplaceOff(struct editor* ed, unsigned int pos, char x);
void    editorScroll(struct editor* ed, int amount);
void    editorScrollOff(struct editor* ed, unsigned int position);
void    editorMode(struct editor* ed, enum editmode mode);
int     editorMsg(struct editor* ed, enum status stts, const char* file, ...);
void    editorUndo(struct editor* ed);
void    editorRedo(struct editor* ed);
void    editorWrite(struct editor* ed);

#endif
