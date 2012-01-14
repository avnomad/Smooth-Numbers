#include <stdio.h>
#include <stdlib.h>

static unsigned int smooth(unsigned int b, unsigned long long i, unsigned long long j)
{
  /*
   * PLACE YOUR CODE HERE...
   */
}

int main(int argc, char* argv[])
{
  unsigned int  b;
  unsigned long long i, j;

  if (argc != 4) {
    printf("Usage: smooth b i j\n"); return 1;
  }
  sscanf(argv[1], "%u",  &b);
  sscanf(argv[2], "%lu", &i);
  sscanf(argv[3], "%lu", &j);
  printf("%d\n", smooth(b, i, j));
  return 0;
}
