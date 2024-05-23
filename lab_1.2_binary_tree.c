#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data; 
    struct Node* left; 
    struct Node* right; 
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    if (node != NULL) {
        node->data = data; 
        node->left = NULL; 
        node->right = NULL; 
        printf("New node created with data: %d\n", data);
    } else {
        printf("Memory allocation failed for the new node\n");
    }
    return node; 
}

void insertNode(struct Node* root, int data) {
    if (root == NULL) return;
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = newNode(data);
        } else {
            insertNode(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = newNode(data);
        } else {
            insertNode(root->right, data);
        }
    }
}

void print_In_Order(struct Node* node) {
    if (node == NULL) 
        return; 
    print_In_Order(node->left);
    printf("%d ", node->data); 
    print_In_Order(node->right); 
}

struct Node* buildBinaryTree() {
    struct Node* root = NULL;
    int numNodes, data;
    printf("Enter the number of nodes you want in the binary tree: ");
    scanf("%d", &numNodes);
    if (numNodes <= 0) {
        printf("Invalid number of nodes. Exiting.\n");
        exit(1);
    }
    printf("Enter the value for the root: ");
    scanf("%d", &data);
    root = newNode(data);
    
    for (int i = 1; i < numNodes; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(root, data);
    }
    return root;
}

int main() {
    struct Node* root = buildBinaryTree();

    printf("Traversal of the binary tree: \n");
    print_In_Order(root); // Print the nodes of the Binary Tree in In-Order traversal
    return 0; 
}
