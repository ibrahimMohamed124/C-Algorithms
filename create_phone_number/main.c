#include <stdio.h>
#include <stdint.h>

char *create_phone_number(char phnum[15], const uint8_t digits[10]) {
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 0) phnum[j++] = '(';
        if (i == 3) phnum[j++] = ')';
        if (i == 3) phnum[j++] = ' ';
        if (i == 6) phnum[j++] = '-';
        phnum[j++] = digits[i] + '0';
    }
    phnum[j] = '\0';
    return phnum;
}

int main() {
    uint8_t digits[10] = {1,2,3,4,5,6,7,8,9,0};
    char phnum[15];
    printf("%s\n", create_phone_number(phnum, digits));
    return 0;
}
