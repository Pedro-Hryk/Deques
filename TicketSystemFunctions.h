#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Line{
    Node* head;
    Node* tail;
}Line;

Node* GetNewNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertOnTail(Line* line, int value){
    
    Node* newNode = GetNewNode(value);
    if(line->tail == NULL){
        line->tail = newNode;
        line->head = newNode;
    }
    else{
        line->tail->next = newNode;
        line->tail = newNode;
    }
}

int CountTicketsInLine(Line* line){
    int elements = 0;
    if(line->head == NULL){
        return elements;
    }

    Node* node = line->head;
    while(node!= NULL){
        node = node->next;
        elements++;
    }
    return elements;
}

void InitializeLine(Line* line){
    line->head = NULL;
    line->tail = NULL;
}

int CallTicket(Line* line){

    if(line->head){

        Node* head = line->head;
        int ticket = head->data;
        Node* newHead= head->next;
        line->head = newHead;
        free(head);

        if(!line->head){
            line->tail = NULL;
        }
        return ticket;
    }
    return -27;
}

int normalTicketsCalled = 0;
bool callPriorityTicket = false;

void TicketManagement(Line* normal, Line* priority){

    int ticketsLeftInNormalLine = CountTicketsInLine(normal);
    int ticketsLeftInPriorityLine = CountTicketsInLine(priority);

    //if lines are empty
    if(ticketsLeftInNormalLine == 0 && ticketsLeftInPriorityLine == 0){  
        printf("No tickets left in both lines!\n");
        return;
    }
    if(ticketsLeftInNormalLine == 0){
        printf("Calling priority ticket %d!\n", CallTicket(priority));
        normalTicketsCalled = 0;
        return;
    }
    else if(ticketsLeftInPriorityLine == 0){
        printf("Calling normal ticket %d!\n", CallTicket(normal));
        normalTicketsCalled++;
        return;
    }
    if(normalTicketsCalled < 3){
        printf("Calling normal ticket %d!\n", CallTicket(normal));
        normalTicketsCalled++;
        return;
    }

    if(normalTicketsCalled == 3){
        printf("Calling priority ticket %d!\n", CallTicket(priority));
        callPriorityTicket = true;
        normalTicketsCalled = 0;
        return;
    }    
}

void Menu(Line normalLine, Line priorityLine){
    int option;
    int normalLineTicket = 0;
    int priorityLineTicket = 1000;
    while(option != 5){
        printf("1. Generate normal line ticket\n");
        printf("2. Generate priority line ticket\n");
        printf("3. Call ticket\n");
        printf("4. See number of tickets left in both lines\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        
        switch(option){
            case 1: 
                normalLineTicket++;
                printf("Your ticket's number is: %d\n", normalLineTicket);
                InsertOnTail(&normalLine, normalLineTicket);                           
                break;
            case 2:
                priorityLineTicket++;
                printf("Your ticket's number is: %d\n", priorityLineTicket);
                InsertOnTail(&priorityLine, priorityLineTicket);
                break;
            case 3:
                TicketManagement(&normalLine, &priorityLine);
                break;
            case 4:
                printf("Number of tickets left in normal line: %d\n", CountTicketsInLine(&normalLine));
                printf("Number of tickets left in priority line: %d\n", CountTicketsInLine(&priorityLine));
                break;
            case 5:
                break;
            default:
                printf("Type a valid option!\n");
                break;
        }
    }
}