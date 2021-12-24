#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void addhead(struct node*&head, int key) {
    if(head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        head -> data = key;
        head -> next = head;
        head -> prev = head;
    }
    else {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> data = key;
        struct node *last = head;
        head->prev->next=temp;
        temp->next=head;
        temp->prev=head->prev;
        head->prev=temp;
        head = temp;
    }
}

void addlast(struct node* temp, struct node*&head) {
    if(!head)
        head = temp;
    else {
        temp -> next = last(head) -> next;
        temp -> prev = last(head);
        last(head) -> next = temp; // last fonksiyonu ile son düğüm bulunuyor
        head -> prev = temp;
    }
}

void concatenate(struct node*& list_1, struct node* list_2){ 
    if(list_l == NULL)
        list_1 = list_2;
    else {
        struct node *last=list_1;
        while(last -> next != list_1)
            last = last -> next;
        last->next=list_2; 
        list2->prev=last; 
        while(last -> next != list_2)
            last = last -> next;
        last->next=list_1; 
        list1->prev=last;
    }
}

void addthen(struct node* other_node, struct node*&head, int n) {
    struct node* temp = head;
    int i = 1;
    while(i < n) {
        head = head -> next;
        i++;
    }
    head -> next -> prev = other_node;
    other_node -> prev = head;
    other_node -> next = head -> next;
    head -> next = other_node;
    head = temp;
}















