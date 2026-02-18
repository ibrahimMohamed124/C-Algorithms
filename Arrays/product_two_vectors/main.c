#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

int length = 4;

bool is_orthogonal(size_t length, const int a[length], const int b[length]){
    int sum =0;

    for(int i =0;i<length;i++)
        sum+= a[i]*b[i];

    return sum == 0;
}

int main(){
    int a[4] = {1,0, 0, 1};
    int b[4] = {0, 1, 1, 0};

    printf("%s\n", is_orthogonal(4, a, b)? "orthogonal" : "not orthogonal");

    return 0;
}
