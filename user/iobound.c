#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i, j;
  
  printf("I/O-bound process started (PID: %d)\n", getpid());
  
  // Simulate I/O-bound work - lots of printing, little CPU
  for(i = 0; i < 50; i++){
    printf("I/O operation %d\n", i);
    
    // Small computation between I/O
    for(j = 0; j < 100; j++){
      // Minimal work
    }
  }
  
  printf("I/O-bound process completed\n");
  exit(0);
}
