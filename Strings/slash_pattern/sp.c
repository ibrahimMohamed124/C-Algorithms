#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);

    if(length < 0){
        printf("Length Must be Positive");
        return 1;
    }

    char* st = malloc(length + 1); //length + null terminator

    st[0] = '\0'; //initialize string

    for(int i =0;i<length/3;i++)
        strcat(st, "//\\");

    printf("%s\n", st);

    free(st);
}
