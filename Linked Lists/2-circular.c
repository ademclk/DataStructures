#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtFront(int key) {
    if(head == NULL) {
        head = (node *)malloc(sizeof(node));
        head->data = key;
        head->next = head;
    }
    else {
        node *temp = (node *)malloc(sizeof(node));
        node *last = head;
        temp->data = key;
        while(last->next != head) 
            last = last->next;
        temp->next = head;
        last->next = temp;
        head = temp;
}
}

void insertAtLast(int key) {
    if(head == NULL) {
        head = (node *)malloc(sizeof(node));
        head->data = key;
        head->next = head;
    }
    else {
        node *temp = (node *)malloc(sizeof(node));
        node *last = head;
        temp->data = key;
        while(last->next != head)
            last = last->next;
        temp->next = head;
        last->next = temp;
}
}

struct node *deletenode(struct node *head, int key) {
    if(head == NULL) {
        printf("Listede eleman yok\n");
        return;
    }
    struct node *temp = head;
    if(head -> data == key) { // ilk düğüm silinecek mi diye kontrol ediliyor.
        struct node *last=head;
        while(last -> next != head)
        last = last -> next;
        head = head -> next; // head artık bir sonraki eleman.
        last->next=head;
        free(temp);
    }
    else if(temp -> next == NULL) { // Listede tek düğüm bulunabilir.
        printf("Silmek istediginiz veri bulunmamaktadir.\n\n");
    }
    else {
        while(temp -> next -> data != key) {
        if(temp -> next -> next == NULL) {
        printf("Silmek istediginiz veri bulunmamaktadir.\n\n");
        return head;
    }
        temp = temp -> next;
    }
    struct node *temp2 = temp -> next;
    temp -> next = temp -> next -> next;
    free(temp2);
    }
    return head;
}

