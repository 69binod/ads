#include <stdio.h>
#include <stdlib.h>

typedef struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct
{
    int size;
    HashNode **table;
} HashTable;

HashNode *createNode(int key, int value)
{
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable *createHashTable(int size)
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (HashNode **)malloc(size * sizeof(HashNode *));
    for (int i = 0; i < size; i++)
    {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

int hash(HashTable *hashTable, int key)
{
    return key % hashTable->size;
}

void insert(HashTable *hashTable, int key, int value)
{
    int index = hash(hashTable, key);
    HashNode *newNode = createNode(key, value);
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

int search(HashTable *hashTable, int key)
{
    int index = hash(hashTable, key);
    HashNode *node = hashTable->table[index];
    while (node != NULL)
    {
        if (node->key == key)
        {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void deleteKey(HashTable *hashTable, int key)
{
    int index = hash(hashTable, key);
    HashNode *node = hashTable->table[index];
    HashNode *prev = NULL;
    while (node != NULL)
    {
        if (node->key == key)
        {
            if (prev == NULL)
            {
                hashTable->table[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void printHashTable(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        HashNode *node = hashTable->table[i];
        while (node != NULL)
        {
            printf("%d %d\n", node->key, node->value);
            node = node->next;
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    HashTable *hashTable = createHashTable(size);

    int choice, key, value;
    while (1)
    {
        printf("1. Insert key-value pair\n");
        printf("2. Search for key\n");
        printf("3. Delete key\n");
        printf("4. Print hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(hashTable, key, value);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            value = search(hashTable, key);
            if (value != -1)
            {
                printf("The value of key %d is: %d\n", key, value);
            }
            else
            {
                printf("Key not found.\n");
            }
            break;
        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteKey(hashTable, key);
            break;
        case 4:
            printHashTable(hashTable);
            break;
        case 5:
            for (int i = 0; i < hashTable->size; i++)
            {
                HashNode *node = hashTable->table[i];
                while (node != NULL)
                {
                    HashNode *temp = node;
                    node = node->next;
                    free(temp);
                }
            }
            free(hashTable->table);
            free(hashTable);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
