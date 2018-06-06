#include "shlel.h"

#define SHLEL_TOK_BUFSIZE 1024
#define SHLEL_TOK_DELIM   " \t\r\n\a"

char ** shlel_split_line(char * line) {
   int bufsize = SHLEL_TOK_BUFSIZE;
   int position = 0;
   char ** tokens = malloc(bufsize * sizeof(char*));
   if (!tokens) {
      fprintf(stderr, "shlel: malloc error\n");
      exit(EXIT_FAILURE);
   }

   char * token = strtok(line, SHLEL_TOK_DELIM);
   while (token != NULL) {
      tokens[position] = token;
      position++;

      if (position >= bufsize) {
         bufsize += SHLEL_TOK_BUFSIZE;
         tokens = realloc(tokens, bufsize * sizeof(char*));
         if (!tokens) {
            fprintf(stderr, "shlel: realloc error\n");
            exit(EXIT_FAILURE);
         }
      }
      token = strtok(NULL, SHLEL_TOK_DELIM);
   }
   tokens[position] = NULL;
      return tokens;
}
