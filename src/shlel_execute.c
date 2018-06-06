#include "shlel.h"

int shlel_execute(char ** args) {
   if (args[0] == NULL) {
      /* empty command */
      return 1;
   }

   for (int i = 0; i < num_functions; ++i) {
      if (strcmp(args[0], functions[i].name) == 0) {
         return functions[i].func(args);
      }
   }
   return shlel_launch(args);
}
