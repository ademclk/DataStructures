#include <stdio.h>
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

void preorder(BTREE *root) {
    if(root != NULL) {
        printf("%d", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(BTREE *root) {
    if(root != NULL) {
        inorder(root -> left);
        printf("%d", root -> data);
        inorder(root -> right);
    }
}

void postorder(BTREE *root) {
    if(root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d", root -> data);
    }
}

BTREE *insert(BTREE *root, int data) {
    if(root != NULL) { // ağaç boş değilse
        if(data < root -> data) // eklenecek veri root’un data’sından küçükse
            root -> left = insert(root -> left, data);

        else
            root -> right = insert(root -> right, data);
    }
    else // eğer ağaç boş ise
        root = new_node(data);
    return root;
}







