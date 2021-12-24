

BTREE* insertBST(BTREE *root, int data) {
    if(root != NULL){
        if(data < root -> data) // data, root’un datasından küçükse
            root -> left = insert(root -> left, data);
        else // data, root’un datasından büyük ya da eşitse
            root -> right = insert(root -> right, data);
    }
    else
        root = new_node(data);
    return root;
}

int size(BTREE *root) {
    if(root == NULL)
        return 0;
    else
        return size(root -> left) + 1 + size(root -> right);
}

int height(BTREE *root) {
    if(root == NULL)
        return -1;
    else {
        int left_height, right_height;
        left_height = height(root -> left);
        right_height = height(root -> right);
        if(right_height > left_height)
            return right_height + 1;
        else
            return left_height + 1;
    }
}

BTREE *delete_node(BTREE *root, int x) {
    BTREE *p, *q;
    if(root == NULL)
        return NULL;
    if(root -> data == x) {
        if(root -> left == root -> right){
            free(root);
            return NULL;
        }
        else {
            if(root -> left == NULL) {
                p = root -> right;
                free(root);
                return p;
            }
            else if(root -> right == NULL){
                p = root -> left;
                free(root);
                return p;
            }
            else {
                p = q = root -> right;
                while(p -> left != NULL)
                    p = p -> left;
                p -> left = root -> left;
                free(root);
                return q;
            }
        }
    }
    else if(root -> data < x)
        root -> right = delete_node(root -> right, x);
    else
        root -> left = delete_node(root -> left, x);
    return root;
}

BTREE* searchtree(BTREE* tree, int data) {
    if(tree != NULL)
        if(tree -> data == data)
            return tree;
        else if(tree -> data > data)
            searchtree(tree -> left, data);
        else
            searchtree(tree -> right, data);
        else
            return NULL;
}

boolean isBST(BTREE* root) { // boolean türü stack kısmında anlatılmıştı
    if(root == NULL)
        return true;
    if(root -> left != NULL && maxValue(root -> left) > root -> data)
        return false;
    if(root -> right != NULL && minValue(root -> right) <= root -> data)
        return false;
    if(!isBST(root -> left) || !isBST(root -> right))
        return false;
    return true;
}

int minValue(BTREE* root) {
    if(root == NULL)
        return 0;
    while(root -> left != NULL)
        root = root -> left;
    return(root -> data);
}

int maxValue(BTREE* root) {
    if(root == NULL)
        return 0;
    while(root -> right != NULL)
        root = root -> right;
    return(root -> data);
}

int isSame(BTREE* a, BTREE* b) {
    if(a == NULL && b == NULL)
        return 1; // İki ağaç da boş ise true döndürür
    else if(a != NULL && b != NULL)
        return (
        a -> data == b -> data && isSame(a -> left, b -> left) &&
        isSame(a -> right, b -> right) // Koşul doğru ise true döndürür
        );
    else
        return 0;
}

int path(BTREE* root, int sum) {
    int pathSum;
    if(root == NULL) // Ağaç NULL ise
        return (sum == 0); // sum 0'a eşitse true dönüyor
    else {
        pathSum = sum - root -> data;
        return (
            path(root -> left, pathSum) ||
            path(root -> right, pathSum)
        );
    }
}

BTREE* copyOdd(BTREE* root, BTREE* root2) {
    if(root != NULL) {
        if(root -> data % 2 == 1)
            root2 = insertBST(root2, root -> data);
        root2 = copyOdd(root -> left, root2);
        root2 = copyOdd(root -> right, root2);
    }
    return root2;
}

