#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int greet_and_add(int (*function)(int, int), int x, int y){
    return function(x, y);
}

int main()
{
    int (*ptr)(int,int) = add;
    int res = ptr(5,3);
    printf("%d\n", res);

    int result2 = greet_and_add(add, 5, 5);
    printf("Hello, the result of addition is %d\n", result2);

    return 0;
}
