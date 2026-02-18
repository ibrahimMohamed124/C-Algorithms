#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void append(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;    
    }

    struct Node* temp = *head;

    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
}

void pushFront(struct Node** head, int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void print_list(struct Node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    print_list(head);

    return 0;
}
