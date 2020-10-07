#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

uint64_t gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    while (v) {                               
        uint64_t t = v;
        v = u % v;
        u = t;
    }
    return u;
}

uint64_t fast_gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    int shift;
    for (shift = 0; !((u | v) & 1); shift++) {
        u >>= 1; v >>= 1;
    }
    while (!(u & 1))
        u >>= 1;
    do {
        while (!(v & 1))
            v >>= 1;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

uint64_t faster_gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    int shift = min(__builtin_ctz(u), __builtin_ctz(v));
    u >>= shift; v >>= shift;
    
    while (!(u & 1))
        u >>= 1;
    do {
        while (!(v & 1))
            v >>= 1;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

int main(int argc, char *argv[])
{
    uint64_t result1 = gcd64(100000, 120000);   
    uint64_t result2 = fast_gcd64(100000, 120000); 
    uint64_t result3 = faster_gcd64(100000, 120000);

    printf("%llu\n%llu\n%llu\n", result1, result2, result3);
}
