#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertAtFirst(int key) {
    if(head == NULL) { // Creating a list if not exists.
        head = (struct node *)malloc(sizeof(struct node));
        head -> data = key;
        head -> next = NULL;
        head -> prev = NULL;
    }
    else {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> data = key;
        temp -> next = head;
        temp -> prev = NULL;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtEnd(int key) {
    if(head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        head -> data = key;
        head -> next = NULL;
        head -> prev = NULL;
}
    else {
        struct node *temp = head;
        struct node *temp2 = (struct node *)malloc(sizeof(struct node));
        while(temp -> next != NULL) // listenin sonunu bulmamız gerekiyor.
            temp = temp -> next;
        temp2 -> data = key;
        temp2 -> next = NULL;
        temp2 -> prev = temp;
        temp -> next = temp2;
    }
}

void addthen(struct node* other_node, struct node*& list, int n) {
    struct node* temp = head;
    int i = 1;
    while(i < n) {
        head = head -> next;
        i++;
    }
    other_node -> prev = head;
    other_node -> next = head -> next;
    head -> next = other_node;
    head = temp;
}

void double_linked_remove(int key) {
    struct node *temp = head;
    if(head -> data == key) {
        head = head -> next;
        head -> prev = NULL;
        free(temp);
    }
    else {
        while(temp -> data != key)
        temp = temp -> next;
    temp -> prev -> next = temp -> next;
    if(temp -> next != NULL)
        temp -> next -> prev = temp -> prev;
    free(temp);
    }
}

struct node* locate(int veri, struct node* head) {
    struct node* locate = NULL;
    while(head != NULL) {
        if(head -> data != veri) {
            head = head -> next; // aranan veri yoksa liste taranıyor
        }
        else {
            locate = head;
            break; // veri bulunursa döngüden çıkılarak geri döndürülüyor
        }
    }
    return locate;
}

bool is_member(struct node* other_node, struct node* head) {
    while(head != NULL && head != other_node)
        head = head -> next;
    return(head == other_node);
}







