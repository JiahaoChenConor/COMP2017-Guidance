#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

volatile int cont = 1;

void sigint_handle(int signum) {
  cont = 0;
  // break the loop
}


int main() {
  //  ctrl + c 
  signal(SIGINT, sigint_handle);


  while(cont) {
    pause(); // pause() will pause the current process (go to sleep) until it is interrupted by a signal.
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t); //statically allocated memory
    printf("%s", asctime(tm_info));
  }

  return 0;
}

