#include <stdio.h>
#include <string.h>

char* token_getter(char str[], const char delimiter[], int index) {
    char *token;
    int count = 0;

    token = strtok(str, delimiter);

    while (token != NULL) {
        if (count == index) {
            return token;
        }
        count++;
        token = strtok(NULL, delimiter);
    }

    return NULL;
}

int main() {
    char str[] = "hello, ibrahim mohamed";
    const char delimiters[] = ",";

    char *result = token_getter(str, delimiters, 1);

    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("Token not found\n");
    }

    return 0;
}
