#include <stdio.h>

unsigned char proc(int color){
    if (color > 255) return 255;
    if (color < 0)   return 0;
    return color;
}

void byte_to_hex(unsigned char v, char *out){
    out[0] = "0123456789ABCDEF"[v >> 4];
    out[1] = "0123456789ABCDEF"[v & 0x0F];
}

void rgb(int r, int g, int b, char hex[7]){
    byte_to_hex(proc(r), &hex[0]);
    byte_to_hex(proc(g), &hex[2]);
    byte_to_hex(proc(b), &hex[4]);
    hex[6] = '\0';
}

int main(void)
{
    char hex[7];

    rgb(255, 255, 255, hex);
    printf("white  : %s\n", hex);

    rgb(0, 0, 0, hex);
    printf("black  : %s\n", hex);

    rgb(255, 165, 0, hex);
    printf("orange : %s\n", hex);

    rgb(-20, 300, 10, hex);
    printf("clamp  : %s\n", hex);

    return 0;
}