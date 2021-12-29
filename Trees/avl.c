#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
};
typedef struct node AVLTREE;

AVLTREE *rightRotate(AVLTREE *z) {
    AVLTREE* temp = z -> left; 
    z -> left = temp -> right; 
    temp -> right = z; 
    z -> height = maxValue(height(z -> left), height(z -> right)) + 1;
    temp -> height = maxValue (height(temp -> left), height(temp -> right)) + 1;
    
    return temp;
}

AVLTREE *leftRotate(AVLTREE *z) {
    AVLTREE *temp = z -> right; 
    z -> right = temp -> left; 
    temp -> left = z; 
    z -> height = maxValue(height(z -> left), height(z -> right)) + 1;
    temp -> height = maxValue (height(temp -> left), height(temp -> right)) + 1;
    
    return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z) {
    z -> left = leftRotate(z -> left); 

    return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z) {
    z -> right = rightRotate(z -> right); 

    return leftRotate(z); 
}

AVLTREE *insertToAVL(int x, AVLTREE *tree){
    if(tree != NULL){
        if(x < tree -> data)
            tree -> left = insertToAVL(x, tree -> left); 
        else if(x > tree -> data)
            tree -> right = insertToAVL(x, tree -> right);
        else
            return tree;
    tree -> height = maxValue(height(tree->left), height(tree->right)) + 1;
        if((height(tree->left) - height(tree->right)) > 1 && x < tree->left->data)
            return RightRotate(tree);
        if((height(tree->left) - height(tree->right)) > 1 && x > tree->left->data)
            return leftRightRotate(tree);
        if((height(tree->left) - height(tree->right)) < -1 && x > tree->right->data)
            return LeftRotate(tree);
        if((height(tree->left) - height(tree->right)) < -1 && x < tree->right->data)
            return rightLeftRotate(tree);
}
    else
        tree = new_node(x);
return tree;
}

int getBalance(AVLTREE* origin) {
    if (origin == NULL)
        return 0;
    return height(origin ->left) - height(origin ->right);
}

AVLTREE *deleteNode(AVLTREE *root, int key) {
    if(root == NULL)
        return root;
    if(key < root -> data) 
        root -> left = deleteNode(root -> left, key);
    else if(key > root -> data) 
        root -> right = deleteNode(root -> right, key);
    else { 
        if((root -> left == NULL) || (root -> right == NULL)) {
            AVLTREE *temp = root -> left ? root -> left : root -> right;

        if(temp == NULL) { 
            temp = root;
            root = NULL;
        } 
        else 
            *root = *temp; 
        free(temp);
    } else {
        AVLTREE *temp = minValue(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
}
    if (root == NULL)
        return root;

root -> height = max(height(root -> left), height(root -> right)) + 1;
if (getBalance(root) > 1 && getBalance(root -> left) >= 0)
    return rightRotate(root);
if (getBalance(root) > 1 && getBalance(root -> left) < 0) {
    root -> left = leftRotate(root -> left); 
    return rightRotate(root);
}
if (getBalance(root) < -1 && getBalance(root -> right) <= 0)
    return leftRotate(root);
if (getBalance(root) < -1 && getBalance(root -> right) > 0) {
    root -> right = rightRotate(root -> right); 
    return leftRotate(root);
}
    return root;
}
