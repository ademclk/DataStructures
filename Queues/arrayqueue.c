#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
typedef struct {
    int front;
    int rear;
    int cnt;
    int data[QUEUE_SIZE];
}queue;

void initialize(queue *q) {
    q -> front = 0;
    q -> rear = -1;
    q -> cnt = 0;
}

typedef enum {false, true}boolean;

boolean isEmpty(queue *q) {
    return(q -> cnt == 0);
}

boolean isFull(queue *q) {
    return(q -> cnt == QUEUE_SIZE);
}

void enqueue(queue *q, int x) {
    if(!isFull(q)) {
        q -> rear ++;
        q -> cnt ++;
        if(q -> rear == QUEUE_SIZE)
            q -> rear = 0;
        q -> data[q -> rear] = x;
    }
}

int dequeue(queue *q) {
    if(!isEmpty) { 
        int x = q -> data[q -> front];
        q -> front++;
        q -> cnt--;
        if(q -> front == QUEUE_SIZE)
            q -> front = 0;
        return x; 
}
}












