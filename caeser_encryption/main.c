#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(char *arr, int size, char target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

char* enc(char *text, int key) {
    char chars[] = "abcdefghijklmnopqrstuvwxyz";
    int chars_len = strlen(chars);
    int text_len = strlen(text);

    char *encrypted = malloc((text_len + 1) * sizeof(char));
    if (!encrypted) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < text_len; i++) {
        int idx = indexOf(chars, chars_len, text[i]);
        if (idx != -1) {
            int newidx = (idx + key) % chars_len;
            encrypted[i] = chars[newidx];
        } else {
            encrypted[i] = text[i];
        }
    }
    encrypted[text_len] = '\0';
    return encrypted;
}

char* dec(char* text, int key) {
    char chars[] = "abcdefghijklmnopqrstuvwxyz";
    int chars_len = strlen(chars);
    int text_len = strlen(text);

    char *decrypted = malloc((text_len + 1) * sizeof(char));
    if (!decrypted) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < text_len; i++) {
        int idx = indexOf(chars, chars_len, text[i]);
        if (idx != -1) {
            int newidx = (idx - key + chars_len) % chars_len;
            decrypted[i] = chars[newidx];
        } else {
            decrypted[i] = text[i];
        }
    }
    decrypted[text_len] = '\0';
    return decrypted;
}

int main() {
    char text[] = "ibrahim";

    char *cipher = enc(text, 3);
    if (cipher) {
        printf("Encrypted: %s\n", cipher);

        char *plain = dec(cipher, 3);
        if (plain) {
            printf("Decrypted: %s\n", plain);
            free(plain);
        }

        free(cipher);
    }
    return 0;
}
