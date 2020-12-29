#ifndef EDITOR_H
#define EDITOR_H
#define INPUT_SIZE 80

#include <stdbool.h>
#include "buffer.h"

enum editmode {
  APPEND      =     0x001,    /*append text after cursor.*/
  APPENDCURR  =     0x002,    /*append text after current cursor position.*/
  NORMAL      =     0x004,    /*normal mode...*/
  INSERT      =     0x008,    /*insert mode...*/
  INSERTLIT   =     0x010,    /*insert literal typed stuff.*/
  REPLACE     =     0x020,    /*replace mode...*/
  CMD         =     0x040,    /*command mode.*/
  SEARCH      =     0x100,    /*searh mode like ctrl+f on browsers.*/
};

enum searchdir {
  FWD,
  BCKWD,
};

enum status {
  INFO,     /*blue bg.*/
  ERROR,    /*red bg.*/
  WARNING,  /*yellow bg.*/
};

struct editor {
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
  char          ib[INPUT_SIZE];
  int           ibindex;
  char          srch[INPUT_SIZE];
};

struct  editor* editorInit();
void    editorCursorPos(struct editor* ed, int pos, int* x, int* y);
void    editorDelAtCursor(struct editor* ed);
void    editorDelOffCursor(struct editor* ed, unsigned int position);
void    editorFree(struct editor* ed);
void    editorIncByte(struct editor* ed, int amount);
void    editorInsByte(struct editor* ed, char x, bool after);
void    editorInsByteOff(struct editor* ed, unsigned int position, char x, bool after);
void    editorMoveCursor(struct editor* ed, int dir, int amount);
void    editorOffCursor(struct editor* ed);
void    editorOpen(struct editor* ed, const char* fn);
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
