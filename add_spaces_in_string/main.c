#include <stdio.h>

int main() {
    char str[] = "ibrahim";

    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);

        if (str[i + 1] != '\0') {
            printf(" ");
        }
    }

    return 0;
}
