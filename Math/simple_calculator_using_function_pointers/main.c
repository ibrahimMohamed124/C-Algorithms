#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int divide(int a, int b){
    return a / b;
}

int main()
{
    int (*operations[4])(int, int) = { add, subtract, multiply, divide };

    int res[4];

    for(int i = 0; i < 4; i++){
        res[i] = operations[i](5, 3);
    }

    for(int i = 0; i < 4; i++){
        printf("%d\n", res[i]);
    }

    return 0;
}
