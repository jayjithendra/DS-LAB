#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* createLinkedListRecursive()
{
    int data;
    struct Node* newNode;
    printf("Enter data (enter -1 to end): ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    newNode = createNode(data);
    printf("Enter next element for %d:\n", data);
    newNode->next = createLinkedListRecursive();
    return newNode;
}
void traverseLinkedListRecursive(struct Node* head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    traverseLinkedListRecursive(head->next);
}
int main()
{
    struct Node* head = NULL;
    printf("Creating a linked list recursively:\n");
    head = createLinkedListRecursive();
    printf("\nTraversing the linked list recursively:\n");
    traverseLinkedListRecursive(head);
    return 0;
}
