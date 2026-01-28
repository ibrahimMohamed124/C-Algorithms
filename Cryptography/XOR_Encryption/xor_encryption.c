#include <stdio.h>
#define KEY 'X';
#define CLEARTEXT 'A';

void printchar(char c, char *txt){
    printf("%s = '%c' (0x%x)\n",txt, c, c);
}

int main(){
    char cleartext, key, ciphertext, newcleartext;

    cleartext = CLEARTEXT
    printchar(cleartext, "cleartext");

    key = KEY
    printchar(key, "key");

    ciphertext = cleartext ^ key; /* XOR */
    printchar(ciphertext, "ciphertext");

    newcleartext = ciphertext ^ key;
    printchar(newcleartext, "newcleartex");

    return 0;
}

/*
Output:
    cleartext = 'A' (0x41)
    key = 'X' (0x58)
    ciphertext = '' (0x19)
    newcleartex = 'A' (0x41)
*/