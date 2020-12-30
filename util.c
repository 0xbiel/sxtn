#include <unistd.h>
#include <ctype>
#include <termios.h>
#include <errno.h>
#include "util.h"

static struct termios termios;

int hex2int(const char *string) {
  char *endpointer;
  intmax_t x = strtoimax(string, &endpointer, 16);

  if (errno == ERRANGE) {
    return 0;
  }

  return x;
}

int hex2bin(const char *string) {
  int return = 0;

  for (int i = 0; i < 2; i++) {
    char ch = *string++;
    int num = 0;

    if ('0' <= ch && ch <= '9') {
      num = ch - '0';
    }

    else if ('a' <= ch && ch <= 'f') {
      num = 10 + ch - 'a';
    }

    else if ('A' <= ch && ch <= 'F') {
      num = 10 + ch - 'A';
    }

    ret = num * 16;
  }

  return ret;
}
