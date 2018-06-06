#ifndef SHLEL_H
#define SHLEL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void    shlel_loop(void);
char *  shlel_read_line(void);
char ** shlel_split_line(char * line);
int     shlel_execute(char ** args);
int     shlel_launch(char ** args);

/* builtin shell commands */
int     shlel_cd(char ** args);
int     shlel_help(char ** args);
int     shlel_exit(char ** args);

/* built-in shell functions */
#define SHLEL_FUNC_T_BUFSIZE 32
typedef struct func_s {
   char name[SHLEL_FUNC_T_BUFSIZE];
   int (*func) (char **);
} shlel_func_t;

int shlel_set_built_in();
shlel_func_t * built_in;
int num_built_in;

#endif
