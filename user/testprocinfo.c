#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

struct procinfo {
  int pid;
  int queue_level;
  int time_slices;
  int wait_time;
  int total_runtime;
};

int
main(int argc, char *argv[])
{
  struct procinfo info;
  
  printf("\n=== Testing getprocinfo System Call ===\n\n");
  
  if(getprocinfo(&info) < 0){
    printf("Error: getprocinfo failed\n");
    exit(1);
  }
  
  printf("Current Process Information:\n");
  printf("  PID:           %d\n", info.pid);
  printf("  Queue Level:   %d\n", info.queue_level);
  printf("  Time Slices:   %d\n", info.time_slices);
  printf("  Wait Time:     %d\n", info.wait_time);
  printf("  Total Runtime: %d\n", info.total_runtime);
  printf("\n");
  
  printf("getprocinfo test PASSED\n\n");
  
  exit(0);
}
