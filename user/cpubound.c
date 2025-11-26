// cpubound.c
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  long i, j;
  volatile int sum = 0;        // volatile prevents optimization away
  long base_iters = 50000000;  // base work amount (tune this)
  int mul = 1;

  if (argc > 1) {
    mul = atoi(argv[1]);      // optional multiplier: e.g. ./cpubound 2
    if (mul < 1) mul = 1;
  }

  long iters = base_iters * mul;

  printf("CPU-bound process started (PID: %d)\n", getpid());

  for (i = 0; i < iters; i++) {
    // inner work kept small to avoid long per-iteration overhead but
    // enough to keep CPU busy; no syscalls here.
    for (j = 0; j < 100; j++) {
      sum += (int)(i * j);
    }
  }

  // print final (possibly overflowed) sum as proof of completion
  printf("CPU-bound process completed. Sum: %d\n", (int)sum);
  exit(0);
}

