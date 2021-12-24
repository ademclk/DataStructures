#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Add head
node *prepend(node *head, int x){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

// Add last
node *append(node *head, int x){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    node *iter = head;
    while (iter->next != NULL){
        iter = iter->next;
    }
    iter->next = temp;
    return head;
}

// Prints all elements in the list
void printlist(node *head){
    if (head == NULL){
        printf("List is NULL\n");
    }
    
    while (head !=NULL){
        printf(" %d -> ",head->data);
        head = head->next;
    }
        printf("NULL");
        printf("\n");
}

// Prints the list recursivly but backwards.
void recursiveprint(node*head){
    if (head == NULL){
        return;
    }
    recursiveprint(head->next); // If you swap this two line it will print in order.
    printf("%d\t",head->data);
}

// Counts the number of elements
int counter(node *head){
    int c = 0;
    while (head != NULL){
        c++;
        head=head->next;
    }
    return c;
}

// Counts but recursively.
int recursivecounter(node *head){
    if (head == NULL){
        return 0;
    }
    return recursivecounter(head->next) + 1;
}

// Searching for an element in the list
/*node *locate(node *head, int x){
    node *locate = NULL;
    while (head !=NULL){
        if (head->data !=x){
            head = head->next;
        }
        else{
            locate = head;
            break;
        }
    return(locate);
}*/

// Removes an given element from the list
node *remover(node *head, int x){
    if (head == NULL){
        printf("List is NULL");
        return head;
    }
    node *temp = head;
    if (head->data == x){
        head = head->next;
        free(temp);
    }
    else if (temp->next == NULL){
        printf("List does not contain the provived data.");
        return head;   
    }
    else{
        while(temp->next->data != x){
            if (temp->next->next == NULL){
                printf("List does not contain the provided data.");
                return head;
            }
            temp = temp->next;
        }
        node *iter = temp->next;
        temp->next = temp->next->next;
        free(iter);
    }
    return head;
}

// Prints the reversed list
void reverse(node *head){
    node *head2 = NULL;
    node *temp = head;
    while (temp != NULL){
        head2 = prepend(head2, temp->data);
        temp = temp->next;
    }
    printlist(head2);
}

node *destroyerpm(node *head){
    if (head == NULL){
        printf("Lists is empty.");
        return head;
    }
    node *iter;
    while (head!=NULL){
        iter=head;
        head = head->next;
        free(iter);
    }
    return head;
}

int main(){
    node *head = NULL;
    printlist(head);
    head = prepend(head,5);
    head = prepend(head,15);
    head = prepend(head,10);
    printlist(head);
    head = append(head,2);
    head = append(head,4);
    head = append(head,8);
    printlist(head);
    recursiveprint(head);
    printf("\nNumber of elements in the list: %d",counter(head));
    printf("\nRecursive count: %d",counter(head));
    printlist(head);
    head = remover(head,2);
    printlist(head);
    reverse(head);
    head = destroyerpm(head);
    printlist(head);

    return 0;
}