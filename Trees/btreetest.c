#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int data) {
    BTREE *p = (BTREE*) malloc(sizeof(BTREE));
    p -> data = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

BTREE *insert(BTREE *root, int data) { // root'u verilmiş ağaca ekleme yapılacak
    if(root != NULL) {
        if(data < root -> data)
            root -> left = insert(root -> left, data);
        else
            root -> right = insert(root -> right, data);
    }else
        root = new_node(data);
    return root;
}

void preorder(BTREE *root) {
    if(root != NULL) {
        printf("%3d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(BTREE *root) {
    if(root != NULL) {
        inorder(root -> left);
        printf("%3d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(BTREE *root) {
    if(root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
    printf("%3d ", root -> data);
    }
}

void mirror(BTREE* root) {
    if(root == NULL)
        return;
    else {
        BTREE* temp;
        mirror(root -> left);
        mirror(root -> right);
        temp = root -> left; // swap işlemi yapılıyor
        root -> left = root -> right;
        root -> right = temp;
    }
}

int main() {
    BTREE *myroot = NULL;
    int i = 0;
    do {
        printf("\n\nAgaca veri eklemek icin sayi giriniz...\nSayi = ");
        scanf("%d", &i);
        if(i != -1)
            myroot = insert(myroot, i);
    } while(i != -1);
    preorder(myroot);
    printf("\n");
    inorder(myroot);
    printf("\n");
    postorder(myroot);
    getch();
    return 0;
}
