#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Function to calculate height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    int left_height = height(node->left);
    int right_height = height(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

// Function to check if the tree is balanced
int isBalanced(struct Node* root) {
    if (root == NULL)
        return 1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
        return 1;
    return 0;
}

// Function to perform right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

// Function to perform left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

// Function to convert BST to AVL tree
struct Node* convertToAVL(struct Node* root) {
    if (root == NULL)
        return root;

    // Check balance factor
    int balance = height(root->left) - height(root->right);

    // Perform rotations if needed
    if (balance > 1) {
        if (height(root->left->left) >= height(root->left->right))
            return rightRotate(root); // LL case
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root); // LR case
        }
    } else if (balance < -1) {
        if (height(root->right->right) >= height(root->right->left))
            return leftRotate(root); // RR case
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root); // RL case
        }
    }

    return root;
}

// Function to perform preorder traversal
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }
    if (!isBalanced(root)) {
        printf("The tree is not balanced.\n");

        int balance = height(root->left) - height(root->right);
        if (balance > 1) {
        if (height(root->left->left) >= height(root->left->right))
            printf("Left-Left rotation required.\n"); // LL case
        else {
            root->left = leftRotate(root->left);
            printf("Left-Right rotation required.\n"); // LR case
        }
    } else if (balance < -1) {
        if (height(root->right->right) >= height(root->right->left))
            printf("Right-Right rotation required.\n"); // RR case
        else {
            root->right = rightRotate(root->right);
            printf("Right-Left rotation required.\n"); // RL case
        }
    }
        root = convertToAVL(root);
        printf("Converted to AVL tree.\n");
    } else {
        printf("The tree is already balanced.\n");
    }

    printf("Preorder traversal of AVL tree:\n");
    preOrder(root);

    return 0;
}
