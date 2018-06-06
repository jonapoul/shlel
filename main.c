#include <stdlib.h>

#include "shlel.h"

int main(int argc, char ** argv) {
   /* configure */
   shlel_set_functions();

   /* command loop */
   shlel_loop();

   /* shutdown/cleanup */
   return EXIT_SUCCESS;
}
