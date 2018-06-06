#include "shlel.h"

int shlel_launch(char ** args) {
   pid_t pid = fork();
   if (pid == 0) {
      /* child process */
      if (execvp(args[0], args) == -1) {
         perror("shlel");
      }
      exit(EXIT_FAILURE);
   } else if (pid < 0) {
      /* error forking */
      perror("shlel");
   } else {
      /* parent process */
      int status;
      do {
         waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
   }
   return 1;
}
