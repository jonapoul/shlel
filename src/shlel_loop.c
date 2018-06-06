#include <stdio.h>

#include "shlel.h"

void shlel_loop(void) {
   char *  line;
   char ** args;
   int     status;

   do {
      printf("shlel > ");
      line   = shlel_read_line();
      args   = shlel_split_line(line);
      status = shlel_execute(args);
      free(line);
      free(args);
   } while (status);
}
