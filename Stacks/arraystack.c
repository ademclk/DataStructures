#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 4

typedef struct{
    int data[STACK_SIZE];
    int top;
}stack;

void push(stack *stk, int c) {
    if(stk -> top == STACK_SIZE - 1)
        printf("\nStack is full.\n\n");
    else {
        stk -> top ++;
        stk -> data[stk -> top] = c;
    }
}

void reset(stack *stk) {
    stk -> top = -1;
}

int pop(stack *stk) {
    if(stk -> top == -1) // stack boş mu diye kontrol ediliyor
        printf("Stack is empty.");
    else {
        int x = stk -> top--; // -- operatörünün işlem sırasına dikkat
        return x; // çıkarılan elemanın indis değeriyle geri dönüyor
    }
}

int main() {
    int x;
    stack n;
    reset(&n);

    push(&n, 4);
    push(&n, 2);
    push(&n, 5);
    push(&n, 7);
    push(&n, 11);

    x = pop(&n);
    printf("%d\n", x);
    x = pop(&n);
    printf("%d\n", x);
    x = pop(&n);
    printf("%d\n", x);
    x = pop(&n);
    printf("%d\n", x);
    x = pop(&n);
    printf("%d\n", x);
    return 0;
}




























































































