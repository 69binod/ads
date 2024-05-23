#include <stdio.h>
#define MAX_NODES 10
char tree[MAX_NODES];

int root(char key) {
    if (tree[0] != '\0')
        printf("Tree already had root");
    else
        tree[0] = key;
    return 0;
}

int left_set(char key, int parent) {
    if (tree[parent] == '\0' || (parent * 2) + 1 >= MAX_NODES)
        printf("Can't set left child, invalid parent index or array bounds exceeded\n");
    else
        tree[(parent * 2) + 1] = key;
    return 0;
}

int right_set(char key, int parent) {
    if (tree[parent] == '\0' || (parent * 2) + 2 >= MAX_NODES)
        printf("\nCan't set right child, invalid parent index or array bounds exceeded");
    else
        tree[(parent * 2) + 2] = key;
    return 0;
}

int print_tree() {
    printf("\n");
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i] != '\0')
            printf("%c", tree[i]);
        else
            printf("-");
    }
    return 0;
}

int main() {
    int numNodes;
    char key;
    int parent;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        printf("Enter key for node %d: ", i);
        scanf(" %c", &key);
        if (i == 0) {
            root(key);
        } else {
            printf("Enter parent index for node %c: ", key);
            scanf("%d", &parent);
            if (parent < 0 || parent >= MAX_NODES) {
                printf("Invalid parent index. Please enter a valid index.\n");
                i--;
            } else {
                if (i % 2 == 1) {
                    left_set(key, parent);
                } else {
                    right_set(key, parent);
                }
            }
        }
    }
    print_tree();
    return 0;
}
