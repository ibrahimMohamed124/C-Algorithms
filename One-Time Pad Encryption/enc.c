#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encrypt(FILE* in, FILE* out, FILE* keyf) {
    int c;
    while ((c = fgetc(in)) != EOF) {
        unsigned char key = rand() & 0xFF;
        unsigned char encrypted = ((unsigned char)c) ^ key;

        fputc(key, keyf);
        fputc(encrypted, out);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    srand((unsigned int)time(NULL));

    FILE* in = fopen(argv[1], "rb");
    FILE* out = fopen("crypt.out", "wb");
    FILE* keyf = fopen("key.out", "wb");

    if (!in || !out || !keyf) {
        printf("File error\n");
        return 1;
    }

    encrypt(in, out, keyf);

    fclose(in);
    fclose(out);
    fclose(keyf);
    return 0;
}
