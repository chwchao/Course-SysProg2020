#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize) {
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    int sum = 0;
    for (int j = 0; j < numsSize; ++j)
      sum += (nums[j] >> i) & 1;
    result += (sum % 3) << i;
  }
  return result;
}

int main(int argc, char *argv[]) {
  int nums[13] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
  printf("Single number: %d\n", singleNumber(nums, 13));
}
