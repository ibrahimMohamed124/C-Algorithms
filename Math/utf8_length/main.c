#include <stdio.h>

int utf8_length(const char *s){
    int count =0;
    while(*s){
        if((*s & 0xC0) != 0x80)
	    count++;
	s++;
    }
    return count;
}

int main(){
    printf("%d\n", utf8_length("Aÿ♠🙉"));
}
