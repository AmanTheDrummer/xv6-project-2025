#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i, j;
  int sum = 0;
  
  printf("CPU-bound process started (PID: %d)\n", getpid());
  
  // Perform CPU-intensive work
  for(i = 0; i < 100000; i++){
    for(j = 0; j < 100; j++){
      sum += i * j;
    }
  }
  
  printf("CPU-bound process completed. Sum: %d\n", sum);
  exit(0);
}
