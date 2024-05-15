#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node* mergeLists(Node* list1, Node* list2)
{
    Node* list3 = NULL;
    Node* current3 = NULL;
    while (list1 != NULL || list2 != NULL)
    {
        if (list1 != NULL)
        {
            if (list3 == NULL)
            {
                list3 = list1;
                current3 = list3;
            }
            else
            {
                current3->next = list1;
                current3 = list1;
            }
            list1 = list1->next;
        }
        if (list2 != NULL)
        {
            if (list3 == NULL)
            {
                list3 = list2;
                current3 = list3;
            }
            else
            {
                current3->next = list2;
                current3 = list2;
            }
            list2 = list2->next;
        }
    }
    return list3;
}
void displayList(struct Node* head)
{
    printf("Merged List: ");
    Node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n, m;
    printf("Enter the size of list1: ");
    scanf("%d", &n);
    printf("Enter elements for list1:\n");
    for (int i = 0; i < n; ++i)
    {
        int value;
        scanf("%d", &value);
        Node* newNode = createNode(value);
        newNode->next = list1;
        list1 = newNode;
    }
    printf("Enter the size of list2: ");
    scanf("%d", &m);
    printf("Enter elements for list2:\n");
    for (int i = 0; i < m; ++i)
    {
        int value;
        scanf("%d", &value);
        Node* newNode = createNode(value);
        newNode->next = list2;
        list2 = newNode;
    }
    Node* list3 = mergeLists(list1, list2);
    displayList(list3);
    while (list3 != NULL)
    {
        Node* temp = list3;
        list3 = list3->next;
        free(temp);
    }
    return 0;
}
