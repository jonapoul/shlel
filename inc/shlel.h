#ifndef SHLEL_H
#define SHLEL_H

#include <stdlib.h>
#include <stdio.h>

void    shlel_loop(void);
char *  shlel_read_line(void);
char ** shlel_split_line(char * line);
int     shlel_execute(char ** args);

#endif
