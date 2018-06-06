#include "shlel.h"

static void shlel_set_func(char * const name,
                           int (*func) (char **),
                           shlel_func_t * sft) {
   strncpy(sft->name, name, sizeof(sft->name));
   sft->func = func;
}

void shlel_set_functions() {
   num_functions = 3;
   functions = malloc(sizeof(shlel_func_t) * num_functions);
   shlel_set_func("cd",   &shlel_cd,   &functions[0]);
   shlel_set_func("help", &shlel_help, &functions[1]);
   shlel_set_func("exit", &shlel_exit, &functions[2]);
}
