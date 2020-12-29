#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include "buffer.h"

struct buffer* bufferCreate() {
  struct buffer* bf = malloc(sizeof(struct buffer));

  if (bf) {
    bf -> contents = NULL;
    bf -> length = 0;
    bf -> capacity = 0;

    return bf;
  }

  else {
    printf("Error: Could not allocate the buffer size.");

    exit(1);
  }
}

void bufferDel(struct buffer* bf) {
  free(bf -> contents);
  free(bf);
}

void bufferApp(struct buffer* bf, const char* file, size_t length) {
  assert(file != NULL);

  if((int)(bf -> length + length) >= bf -> capacity) {
    bf -> capacity += length;
    bf -> capacity *= 2;
    bf -> contents = realloc(bf -> contents, bf -> capacity);

    if(bf -> contents == NULL) {
      printf("Error: Could not reallocate the buffer.");
      exit(1);
    }
  }

  memcpy(bf -> contents + bf -> length, file, length);
  bf -> length += length;
}

int bufferAppf(struct buffer* bf, const char* file, ...) {
  assert(strlen(file) < BUFFER_SIZE);
  char buffer[BUFFER_SIZE];
  va_list append;

  va_start(append, file);

  int length = vsnprintf(buffer, sizeof(buffer), file, append);
  va_end(append);

  bufferApp(bf, buffer, length);
  return length;
}

void bufferWrite(struct buffer* bf) {
  if(write(STDOUT_FILENO, bf -> contents, bf -> length) == - 1) {
    printf("Error: Could not write the buffer.");
    exit(1);
  }
}
