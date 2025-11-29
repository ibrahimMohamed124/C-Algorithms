#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isAnagram(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2))
        return 0;

    int count[256] = {0};

    for (int i = 0; i < strlen(s1); i++) {
        count[(unsigned char)tolower(s1[i])]++;
        count[(unsigned char)tolower(s2[i])]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main() {
    const char *a = "listen";
    const char *b = "silent";

    if (isAnagram(a, b))
        printf("is anagram\n");
    else
        printf("not anagram\n");

    return 0;
}
