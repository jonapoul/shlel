#include <unistd.h>
#include <stdio.h>

#include "shlel.h"

int shlel_cd(char ** args){
   if (args[1] == NULL) {
      fprintf(stderr, "shlel: expected argument to 'cd'\n");
   } else if (chdir(args[1]) != 0) {
      perror("shlel");
   }
   return 1;
}
