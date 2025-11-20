#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWordInFile(const char *filename, const char *oldWord, const char *newWord) {
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("temp.txt", "w");
    char w[100];

    // check null
    if (f == NULL || f2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // read every single word
    while (fscanf(f, "%s", w) != EOF) { // EOF refers to end of file
        if (strcmp(w, oldWord) == 0)
            fprintf(f2, "%s ", newWord);
        else
            fprintf(f2, "%s ", w);
    }

    fclose(f);
    fclose(f2);

    f = fopen(filename, "w");
    f2 = fopen("temp.txt", "r");

    char c;
    while (fscanf(f2, "%c", &c) != EOF) {
        fprintf(f, "%c", c);
    }

    fclose(f);
    fclose(f2);
    scanf("%*s");
    remove("temp.txt");
}

int main() {
    char word[50], cword[50];

    start:
    printf("Enter the word you want to replace: ");
    scanf("%s", word);

    printf("Enter the corrected word: ");
    scanf("%s", cword);

    replaceWordInFile("file.txt", word, cword);

    printf("Replacement done successfully.\n");
    goto start;
    return 0;
}
