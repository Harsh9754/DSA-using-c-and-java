//BST

#include <stdio.h>
#include <stdlib.h>


struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int key) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}


struct node* insert(struct node* root, int key) {

    if (root == NULL)
    {
    return newNode(key);
    }
    if (key < root->key)
    {
    root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
     root->right = insert(root->right, key);
    }
    return root;
}


struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL){
        current = current->left;
}
    return current;
}


struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
}
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // copy the inorder successor's content to this node
        root->key = temp->key;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key)
    {
       return root;
    }
    if (root->key < key)
    {
       return search(root->right, key);
}
else{
    return search(root->left, key);
 }
}

// function to traverse the binary search tree in inorder
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main() {
    struct node* root = NULL;
    int choice, key;

    while(1) {
        printf("\nBinary Search Tree Operations\n");
        printf("----------------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse (Inorder)\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted in tree\n", key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                if (root == NULL) {
                    printf("Tree is empty now\n");
                } else {
                    printf("Key %d deleted from tree\n", key);
                }
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                struct node* result = search(root, key);
                if (result == NULL) {
                    printf("Key %d not found in tree\n", key);
                } else {
                    printf("Key %d found in tree\n", key);
                }
                break;
            case 4:
                printf("Inorder traversal of tree: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }

    }

    return 0;
}
