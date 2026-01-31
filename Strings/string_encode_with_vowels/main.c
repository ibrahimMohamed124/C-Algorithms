#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



char* encode(const char *string) {
    const char *vowels = "aeiou";
    char *encoded = malloc(strlen(string) + 1);
    strcpy(encoded, string);

    for (int i = 0; encoded[i] != '\0'; i++) {
        char c = tolower(string[i]);
        char *pos = strchr(vowels, c);
        if (pos) {
            encoded[i] = '1' + (pos - vowels);
        }
    }
    return encoded;
}

char* decode(const char *string) {
    const char *vowels = "aeiou";
    char *decoded = malloc(strlen(string) + 1);
    strcpy(decoded, string);

    for (int i = 0; decoded[i] != '\0'; i++) {
        if (isdigit(string[i])) {
            int index = string[i] - '1';
            if (index >= 0 && index < 5) {
                decoded[i] = vowels[index];
            }
        }
    }
    return decoded;
}

int main(void) {
    const char *text = "How are you today?";

    char *encoded = encode(text);
    char *decoded = decode(encoded);

    printf("Original: %s\n", text);
    printf("Encoded : %s\n", encoded);
    printf("Decoded : %s\n", decoded);

    free(encoded);
    free(decoded);

    return 0;
}



