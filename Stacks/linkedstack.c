#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct node *top;
    int cnt;
}stack

typedef enum {false, true}boolean;

boolean isEmpty(stack *stk) {
    return(stk -> cnt == 0); // parantez içerisindeki ifadeye dikkat
}

boolean isFull(stack *stk) {
    return(stk -> cnt == STACK_SIZE);
}

void push(stack *stk, int c) {
    if(!isfull(stk)) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> data = c;
        temp -> next = stk -> top;
        stk -> top = temp;
        stk -> cnt++;
    }
    else
    printf("Stack is full.\n");
}

int pop(stack *stk) {
    if(!isEmpty(stk)) { // stack boş değilse
        struct node *temp = stk -> top;
        stk -> top = stk -> top -> next;
        int x = temp -> data;
        free(temp);
        stk -> cnt--;
        return x;
    }
}

int top(stack *stk) {
    if(!isEmpty(stk))
        return(stk -> top -> data);
}

void initialize(stack *stk) {
    stk -> top = NULL;
    stk -> cnt = 0;
}









