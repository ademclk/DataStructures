#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
typedef struct {
    int cnt;
    struct node *front;
    struct node *rear;
}queue;

void initialize(queue *q) {
    q -> cnt = 0;
    q -> front = q -> rear = NULL; 
}

int isEmpty(queue *q) {
    return(q -> cnt == 0);
}

int isFull(queue *q) {
    return(q -> cnt == QUEUE_SIZE);
}

void enqueue(queue *q, int x) {
    if(!isFull(q)) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> next = NULL;
        temp -> data = x;
    if(isEmpty(q))
        q -> front = q -> rear = temp;
    else {
        q -> rear -> next = temp;
        q -> rear = temp;
    }
    q -> cnt ++;
    }
}

int dequeue(queue *q) {
    if(!isEmpty(q)) { 
        struct node *temp = q -> front;
        int x = temp -> data; 
        q -> front = temp -> next;
        free(temp); 
        q -> cnt--;
        return x; 
    }
}














