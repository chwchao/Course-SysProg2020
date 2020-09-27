#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t hexchar2val(uint8_t in) {
  const uint8_t letter = in & 0x40;
  const uint8_t shift = (letter >> 3) | (letter >> 6);
  return (in + shift) & 0xf;
}

uint64_t hexspeak(char str[]) {
  int len = strlen(str);
  assert(len <= 18 && len > 2);
  assert(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'));

  uint64_t result = 0;
  for (int i = len - 1; i >= 2; --i) {
    result |= (uint64_t)hexchar2val(str[i]) << ((len - i - 1) << 2);
  }
  return result;
}

int main(int argc, char *argv[]) {
  char str1[] = "0xFF";
  char str2[] = "0xCAFEBABE";
  char str3[] = "0x8BADF00D";

  printf("%s: %llu\n", str1, hexspeak(str1));
  printf("%s: %llu\n", str2, hexspeak(str2));
  printf("%s: %llu\n", str3, hexspeak(str3));

  return 0;
}
