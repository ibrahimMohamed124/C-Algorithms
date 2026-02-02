#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countDigits(long long n) {
    if (n == 0) return 1;
    if (n < 0) n = -n;

    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

long long getDigit(long long n, long long place) {
    int digit = (n / place) % 10;
    return digit * place;
}

char* expandedForm(long long n) {
    int len = countDigits(n);

    char* expanded = malloc((len * 20) + 1);
    if (!expanded) return NULL;

    expanded[0] = '\0';

    long long place = 1;
    bool first = true;

    while (place <= llabs(n)) {
        long long value = getDigit(n, place);

        if (value != 0) {
            char buffer[32];

            if (!first)
                strcat(expanded, " + ");

            snprintf(buffer, sizeof(buffer), "%lld", value);
            strcat(expanded, buffer);

            first = false;
        }

        place *= 10;
    }

    return expanded;
}

int main() {
    char *res = expandedForm(70304);
    if (res) {
        printf("%s\n", res);  // 70000 + 300 + 4
        free(res);
    }
    return 0;
}
