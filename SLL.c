#include <stdio.h>
#include <stdlib.h>

// Linked list node
    struct Node{
        int data;
        struct Node* next;
    };

// Printing all elements
    void printLl(struct Node* n){
        if (n==NULL)
            printf("Empty list");
        
        else {
            while (n != NULL){
                printf(" %d ", n->data);
                n = n->next;
            }
            printf("\n");
        }
    }

// Recursivly printing all elements
    int printrecll(struct Node* h){
        
    if (h == NULL){
        return 1;
        }
    printf(" %d ",h->data);
        return printrecll(h->next);
    }
// Adding a element to head
    struct Node* addHead(struct Node* head, int tdata){
        // Allocating memory for new node to add
        struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
        newnode->data = tdata;
        newnode->next = head;
        head = newnode;
        return head;
}

// Inserting an element between two nodes
    struct Node* insertBetween(struct Node* headr,int data){
        if (headr == NULL){
            printf("Given node cannot be NULL");
            return headr;
        }
        struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = headr->next;
        headr->next = newnode;
        return headr;
    }

    struct Node* addEnd(struct Node* head, int data){
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        struct Node* iter = head;

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL){
            head = newnode;
            return head;
        }
        
        while (iter->next !=NULL){
            iter = iter->next;
        }
        iter->next=newnode;
        return head;
    }

    struct Node* deleteKey(struct Node *head, int key){
            if (head == NULL){
                printf("List is empty");
                return 0;
            }
            struct Node* iter =head;
            if (head->data == key){
                head = head->next;
                free(iter);
            }

            else if (iter->next == NULL){
                printf("Process unexpected.");
                return head;
            }
            else{
                while (iter->next->data !=key){
                    if (iter->next->next == NULL){
                        printf("Process unexpected.");
                        return head;
                    }
                    iter = iter ->next;
                } 
                struct Node *iter2= iter->next;
                iter->next = iter->next->next;
                free(iter2); 
            }
            return head;
    }

    int iterativeCount(struct Node* head){
        int counter = 0;
        struct Node* iter = head;
        while (iter != NULL)
        {
            counter ++;
            iter = iter->next;

        }
        return counter;
    }

    int recursiveCount(struct Node* head){
        if (head==NULL)
        {
            return 0;
        }
        else
        {
            return 1 + recursiveCount(head->next);
        }
        
    }
    struct Node* reverseLL(struct Node* head){
        
        struct Node* temp = NULL;
        struct Node* iter = head;
        struct Node* iter2 = NULL;

        while (iter !=NULL)
        {
            iter2 = iter->next;
            iter->next = temp;
            temp = iter;
            iter = iter2;
        }
        head = temp;
    }
int main()
{
// Normally we don't have to do same process for every node basically use next
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 6;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 7;
    third->next = NULL;
        printLl(head);
    head = addHead(head,65);
        printLl(head);
    insertBetween(head->next,4);
        printLl(head);
    head = addEnd(head,31);
        printLl(head);
    head = deleteKey(head,2);
        printLl(head);
    printf("Count of nodes %d ",iterativeCount(head));
    printf("ReCount of nodes %d",recursiveCount(head));
    
    head = reverseLL(head);
    printLl(head);

    return 0;
}
