#include <stdio.h>
#include <stdlib.h>

char* hashtag_generate(const char *s) {

    /* calculate length manually */
    int len = 0;
    while (s[len])
        len++;

    /* allocate max needed space */
    char *out = (char*)malloc(len + 2);
    if (!out) return 0;

    char *dst = out;
    int new_word = 1;

    *dst++ = '#';

    while (*s) {
        char c = *s++;

        if (c == 0x20) {        /* space */
            new_word = 1;
            continue;
        }

        if (new_word) {
            /* lowercase -> uppercase (bitwise) */
            if (c >= 'a' && c <= 'z')
                c &= ~0x20;

            new_word = 0;
        }

        *dst++ = c;
    }

    *dst = 0;
    return out;
}

int main(){
    
}