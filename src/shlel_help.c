#include <stdio.h>

#include "shlel.h"

int shlel_help(char ** args) {
   printf("Stephen Brennan's LSH\n");
   printf("Type program names and arguments, and hit enter.\n");
   printf("The following are built in:\n");

   for (int i = 0; i < num_functions; i++) {
      printf("\t'%s'\n", functions[i].name);
   }

   printf("Use the man command for information on other programs.\n");
   return 1;
}
