#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char txt[] = "hello, ibrahim";
    char* token = strtok(txt, ",");
    char* parts[10];
    int count = 0;

    while (token != NULL) {
        parts[count++] = token;     // store parts splitted
        token = strtok(NULL, ",");  // get the next part
    }

    printf("%s", parts[0]); // hello
    printf("%s", parts[0]); // ibrahim
    return 0;
}
