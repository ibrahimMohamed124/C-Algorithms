#include <stdio.h>
#include <stdbool.h>

unsigned toggleBit(unsigned n, unsigned pos){
    return n ^ (1u << pos);
}

unsigned setBit(unsigned n, unsigned pos){
    return n | (1u << pos);
}

unsigned clearBit(unsigned n, unsigned pos){
    return n & ~(1u << pos);
}

bool isBitSet(unsigned n, unsigned pos){
    return (n & (1u << pos)) != 0;
}

unsigned setMultipleBit(unsigned n, unsigned mask){
    return n | mask;
}

unsigned clearMultipleBits(unsigned n, unsigned mask){
    return n & ~mask;
}

unsigned toggleMultipleBits(unsigned n, unsigned mask){
    return n ^ mask;
}

int main(){

    unsigned n = 5;   // 0101

    printf("Original: %u\n", n);

    printf("toggleBit(5,1) = %u\n", toggleBit(n,1));        // 7
    printf("setBit(5,1) = %u\n", setBit(n,1));              // 7
    printf("clearBit(7,1) = %u\n", clearBit(7,1));          // 5
    printf("isBitSet(5,0) = %d\n", isBitSet(n,0));          // 1 (true)

    printf("setMultipleBit(5,3) = %u\n", setMultipleBit(5,3));      // 7
    printf("clearMultipleBits(7,2) = %u\n", clearMultipleBits(7,2)); // 5
    printf("toggleMultipleBits(5,3) = %u\n", toggleMultipleBits(5,3)); // 6

    return 0;
}
