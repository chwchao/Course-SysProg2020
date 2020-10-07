#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define asr_i(m, n)                                                            \
  _Generic((m), int8_t                                                         \
           : asr_i8, int16_t                                                   \
           : asr_i16, int32_t                                                  \
           : asr_i32, int64_t                                                  \
           : asr_i64)(m, n)

#define asr(type)                                                              \
  const type logical = (((type)-1) >> 1) > 0;                                  \
  u##type fixu = -(logical & (m < 0));                                         \
  type fix = *(type *)&fixu;                                                   \
  return (m >> n) | (fix ^ (fix >> n));

int8_t asr_i8(int8_t m, unsigned int n) { asr(int8_t); }

int16_t asr_i16(int16_t m, unsigned int n) { asr(int16_t); }

int32_t asr_i32(int32_t m, unsigned int n) { asr(int32_t); }

int64_t asr_i64(int64_t m, unsigned int n) { asr(int64_t); }

int main(int argc, char *argv[])
{
  int8_t i8 = -1;
  printf("%d\n", i8);

  int16_t i16 = -1;
  printf("%d\n", i16);

  int32_t i32 = -1;
  printf("%d\n", i32);

  int64_t i64 = -1;
  printf("%lld\n", i64);
}
