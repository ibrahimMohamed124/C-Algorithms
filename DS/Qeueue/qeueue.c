#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear  = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return -1;
    }

    int value = q->arr[q->front];
    q->front++;

    // reset when queue becomes empty
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Front (peek): %d\n", peek(&q));

    // test filling
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70); // should fill (MAX = 7)
    enqueue(&q, 80); // should print FULL

    display(&q);

    return 0;
}
