#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initialize(Stack *s){
    s->top = -1;
}

int isFull(Stack *s){
    return s->top == MAX -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s,int value){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return;
    }
    for(int i = s->top;i >=0;i--){
        printf("%d\n",s->arr[i]);
    }
}

int main()
{
    Stack s;
    initialize(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);

    printf("Stack elements: \n");
    display(&s);

    printf("Pop element: \n");
    printf("%d\n", pop(&s));

    printf("Stack after pop: \n");
    display(&s);

    return 0;
}
