#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numSize) {
  int result = 0;
  for (int i = 0; i < numSize; ++i)
    result ^= nums[i];
  return result;
}

int main(int argc, char *argv[]) {
  int nums[9] = {0, 0, 1, 1, 2, 2, 3, 4, 4};
  printf("Single number: %d\n", singleNumber(nums, 9));
}
