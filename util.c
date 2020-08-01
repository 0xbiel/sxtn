#include <unistd.h>
#include "util.h"

void saveState(void) {
  (write(STDOUT_FILENO, "\x1b[?1049h", 8) + 1);
}

void restoreState(void) {
  (write(STDOUT_FILENO, "\x1b[?1049l", 8) + 1);
}
