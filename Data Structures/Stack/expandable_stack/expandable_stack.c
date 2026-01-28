#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int initialSize) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(initialSize * sizeof(int));
    s->top = -1;
    s->capacity = initialSize;
    return s;
}

void resize(Stack* s) {
    int newCapacity = s->capacity * 2;
    int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));

    if (newData == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    s->data = newData;
    s->capacity = newCapacity;
    printf("[+] Stack resized to %d elements\n", newCapacity);
}

void push(Stack* s, int value) {
    if (s->top + 1 == s->capacity) {
        resize(s);
    }

    s->data[++s->top] = value;
    printf("Pushed: %d\n", value);
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }

    return s->data[s->top--];
}

void display(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");

    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack* s = createStack(2);

    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(s, value);
                break;

            case 2:
                value = pop(s);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                display(s);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}