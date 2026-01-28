#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* setString(char* str){
    char *s = malloc(strlen(str) + 1); // +1 for '\0'
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s, str);
    return s;  
}

int main(){
    int students[20]; // static memory
    printf("Size of students array: %zu bytes\n", sizeof(students));

    char str[] = "ibrahim";
    char *copied = setString(str);
    printf("Copied string: %s\n", copied);

    free(copied); // free memory

    return 0;
}
