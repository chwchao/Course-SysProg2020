#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

bool is_alpha(const char str[], size_t size) {
  if (size == 0)
    return false;
  int i = 0;
  while ((i + 8) <= size) {
    uint64_t payload;
    memcpy(&payload, str + i, 8);

    uint64_t A = payload + PACKED_BYTE(128 - 'A');
    uint64_t Z = payload + PACKED_BYTE(128 - 'Z' - 1);
    uint64_t a = payload + PACKED_BYTE(128 - 'a');
    uint64_t z = payload + PACKED_BYTE(128 - 'z' - 1);

    uint64_t lower_mask = ((a ^ z) & PACKED_BYTE(0x80));
    uint64_t upper_mask = ((A ^ Z) & PACKED_BYTE(0x80));

    if ((lower_mask | upper_mask) ^ PACKED_BYTE(0x80))
      return false;
    i += 8;
  }
  while (i < size) {
    if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
      return false;
    i++;
  }
  return true;
}

int main(int argc, char *argv[]) {
  char str1[] = "aBcDeFgHiJkLmNoPqRsTuVwXyZ";
  char str2[] = "@%^&*($%^&*(*&^%$#$%^&*(*&";
  char str3[] = "abcd%^&*(EFGH$%^&*IJKL1234";

  printf("\"%s\" is %sall alpha.\n", str1, is_alpha(str1, 26) ? "" : "not ");
  printf("\"%s\" is %sall alpha.\n", str2, is_alpha(str2, 26) ? "" : "not ");
  printf("\"%s\" is %sall alpha.\n", str3, is_alpha(str3, 26) ? "" : "not ");
}
