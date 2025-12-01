#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;      // buffer
    size_t capacity; // allocated size
    size_t length;   // current length
} StringBuilder;

void sb_init(StringBuilder *sb){
    sb->capacity = 64;
    sb->length = 0;
    sb->data = malloc(sb->capacity);
    if(!sb->data){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    sb->data[0] = '\0';
}

void sb_free(StringBuilder *sb){
    free(sb->data);
}

void sb_append(StringBuilder *sb, const char *str){
    size_t new_len = sb->length + strlen(str);
    if(new_len + 1 > sb->capacity){
        while(sb->capacity < new_len + 1){
            sb->capacity *= 2;
        }
        sb->data = realloc(sb->data, sb->capacity);
        if(!sb->data){
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }

    strcpy(sb->data + sb->length, str);
    sb->length = new_len;
}

const char* sb_get(StringBuilder *sb){
    return sb->data;
}

int main() {
    StringBuilder sb;
    sb_init(&sb);

    sb_append(&sb, "Hello ");
    sb_append(&sb, "Ibrahim ");
    sb_append(&sb, "your C skills are growing!");

    printf("%s\n", sb_get(&sb));

    sb_free(&sb);
    return 0;
}
