#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#include "shlel.h"

int shlel_mkdir(char ** args) {
   if (args[1] == NULL) {
      fprintf(stderr, "shlel: expected argument to 'mkdir'\n");
   } else {
      int flags = 0;
      if (mkdir(args[1], flags) != 0) {
         perror("shlel");
      }
   }
   return 1;
}
