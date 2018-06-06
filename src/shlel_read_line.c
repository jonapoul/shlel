#include <stdio.h>

#include "shlel.h"

char * shlel_read_line(void) {
   char * line = NULL;
   size_t bufsize = 0;
   getline(&line, &bufsize, stdin);
   return line;
}
