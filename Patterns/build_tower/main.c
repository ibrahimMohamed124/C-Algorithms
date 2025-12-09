#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *strdata;
    int capacity;
    int length;
} StringBuilder;

void initialize_sb(StringBuilder *sb){
    sb->capacity = 64;
    sb->length = 0;
    sb->strdata = malloc(sb->capacity);
}

void free_sb(StringBuilder *sb){
    free(sb->strdata);
}

void append(StringBuilder *sb, const char *str){
    int new_length = sb->length + strlen(str);
    if(new_length + 1 < sb->capacity){
        while(sb->capacity < new_len + 1){
            sb->capacity *= 2;
        }
    }
    sb->strdata = realloc(sb->strdata,sb->capacity);

    if(!sb->strdata){
        printf("Memory reallocation failed\n");
        exit(1);
    }
    strcpy(sb->data + sb->length, str);
    sb->length = new_len;
}

const char* get_sb(StringBuilder *sb){
    return sb->strdata;
}

int main()
{

    return 0;
}


