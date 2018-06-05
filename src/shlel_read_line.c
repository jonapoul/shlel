#include "shlel.h"

#define SHLEL_RL_BUFSIZE 1024

char * shlel_read_line(void) {
   int bufsize  = SHLEL_RL_BUFSIZE;
   int position = 0;
   int c;

   char * buffer = malloc(sizeof(char) * bufsize);
   if (!buffer) {
      fprintf(stderr, "shlel: malloc error\n");
      exit(EXIT_FAILURE);
   }

   while (1) {
      /* Read character */
      c = getchar();
      /* If EOF, replace with null and return the input line */
      if (c == EOF || c == '\n') {
         buffer[position] = '\0';
         return buffer;
      } else {
         buffer[position] = c;
      }
      position++;

      /* if the buffer size is exceeded, reallocate */
      if (position >= bufsize) {
         bufsize += SHLEL_RL_BUFSIZE;
         buffer = realloc(buffer, bufsize);
         if (!buffer) {
            fprintf(stderr, "shlel: realloc error\n");
            exit(EXIT_FAILURE);
         }
      }
   }
}
