#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize, int time) {
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    int sum = 0;
    for (int j = 0; j < numsSize; ++j)
      sum += (nums[j] >> i) & 1;
    result += (sum % time) << i;
  }
  return result;
}

int main(int argc, char *argv[]) {
  int nums_2[13] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7};
  int nums_3[13] = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4, 5, 5, 5};
  int nums_4[13] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 4, 4};
  int nums_5[16] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4, 4, 4, 4};

  printf("Single number for 2: %d\n", singleNumber(nums_2, 13, 2));
  printf("Single number for 3: %d\n", singleNumber(nums_3, 13, 3));
  printf("Single number for 4: %d\n", singleNumber(nums_4, 13, 4));
  printf("Single number for 5: %d\n", singleNumber(nums_5, 16, 5));
}
