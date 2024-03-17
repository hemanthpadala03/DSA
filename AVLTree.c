#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Define the structure for an AVL tree node
typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Function to create a new node
AVLNode* createNode(int data) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    if (newNode == NULL) {
        printf("Error! unable to create a new node\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New nodes are leaf nodes with height 1
    return newNode;
}

// Function to calculate the height of a node
int height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to perform right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Function to perform left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Function to insert a node into the AVL tree
AVLNode* insertNode(AVLNode* node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else // Equal data is not allowed in BST
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = height(node->left) - height(node->right);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to perform in-order traversal
void inOrder(AVLNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


int main() {
    AVLNode* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    // In-order traversal of the constructed AVL tree
    printf("In-order traversal of the constructed AVL tree is \n");
    inOrder(root);

    return 0;
}
