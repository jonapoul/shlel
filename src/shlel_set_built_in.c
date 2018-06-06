#include "shlel.h"

static void shlel_set_func(char const * const name,
                           int (*func) (char **)) {

}

int shlel_set_built_in() {
   built_in = malloc(sizeof(shlel_func_t) * 3);
   built_in[0].name = "cd";   built_in[0].func = &shlel_cd;
   built_in[0].name = "help"; built_in[0].func = &shlel_help;
   built_in[0].name = "exit"; built_in[0].func = &shlel_exit;
}
