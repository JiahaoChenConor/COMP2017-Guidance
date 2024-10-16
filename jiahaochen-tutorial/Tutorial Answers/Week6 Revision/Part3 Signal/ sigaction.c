#include <stdio.h>
#include <signal.h>

void sigint_handler(int signo, siginfo_t* sinfo, void* context) {
  printf("I was interrupted\n");
}

int main() {
  struct sigaction sig;
  memset(&sig, 0, sizeof(struct sigaction));
  
  sig.sa_sigaction = sigint_handler; //SETS Handler
  sig.sa_flags = SA_SIGINFO;
  
  if(sigaction(SIGINT, &sig, NULL) == -1) {
    perror("sigaction failed");
    return 1;
  }
}