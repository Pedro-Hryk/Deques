#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Deque{
    Node* head;
    Node* tail;
}Deque;

Node* GetNewNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void InsertOnDeque(int value, Deque* deque){
    Node* newNode = GetNewNode(value);

    if(!deque->tail){
        deque->head = newNode;
        deque->tail = newNode;
    }
    else{
        deque->tail->next = newNode;
        deque->tail = newNode;
    }
}

int CountElementsInDeque(Deque deque){
    int elements = 0;
    if(deque.head == NULL){
        return elements;
    }

    Node* node = deque.head;
    while(node!= NULL){
        node = node->next;
        elements++;
    }
    return elements;
}

int RemoveFromDeque(Deque* deque){
    if(deque->head){
        Node* head = deque->head;
        int ticket = head->data;
        Node* newHead= head->next;
        deque->head = newHead;
        free(head);

        if(!deque->head){
            deque->tail = NULL;
        }
        return ticket;
    }
    return -27;

}

void InitializeDeque(Deque* deque){
    deque->head = NULL;
    deque->tail = NULL;
}

int main(){

    Deque firstLine;
    InitializeDeque(&firstLine);
    printf("Number of elements in line: %d\n", CountElementsInDeque(firstLine));
    InsertOnDeque(1, &firstLine);
    printf("Number of elements in line: %d\n", CountElementsInDeque(firstLine));

    InsertOnDeque(2, &firstLine);
    InsertOnDeque(3, &firstLine);
    InsertOnDeque(4, &firstLine);
    printf("Number of elements in line: %d\n", CountElementsInDeque(firstLine));

    printf("Element at head: %d\n", firstLine.head->data);
    printf("Element at tail: %d\n", firstLine.tail->data);

    int ticket;
    ticket = RemoveFromDeque(&firstLine);
    printf("Ticket completed: %d\n", ticket);
    printf("Number of elements in line after removal of ticket: %d\n", CountElementsInDeque(firstLine));
    printf("Element at head: %d\n", firstLine.head->data);
    printf("Element at tail: %d\n", firstLine.tail->data);
    

    return 1;
}