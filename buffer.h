#include <stdlib.h>

#ifndef BUFFER_H
#define BUFFER_H

static const unsigned int BUFFER_SIZE = 1024;

struct buffer { /*char sequence to render the screen*/
  char* contents;
  int length;
  int capacity;
}

struct buffer* bufferCreate();

void bufferDel(struct buffer* bf);

void bufferApp(struct buffer* bf, const char* file, size_t length); /*buffer append file writing bytes length*/

int bufferAppf(struct buffer* bf, const char* file, ...); /*buffer appendf appends file but with formatted text.*/

void bufferWrite(struct buffer* bf);

#endif
