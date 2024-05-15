#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node* mergeLists(Node* X,Node* Y) {
    Node* Z = NULL;
    Node* currentZ = NULL;
    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            if (Z == NULL) {
                Z = X;
                currentZ = Z;
            } else {
                currentZ->next = X;
                currentZ = X;
            }
            X = X->next;
        } else {
            if (Z == NULL) {
                Z = Y;
                currentZ = Z;
            } else {
                currentZ->next = Y;
                currentZ = Y;
            }
            Y = Y->next;
        }
    }
    if (X != NULL) {
        if (Z == NULL) {
            Z = X;
        } else {
            currentZ->next = X;
        }
    } else if (Y != NULL) {
        if (Z == NULL) {
            Z = Y;
        } else {
            currentZ->next = Y;
        }
    }
    return Z;
}
void displayList(Node* head) {
    printf("Merged List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Node* X = createNode(1);
    X->next = createNode(3);
    X->next->next = createNode(5);
    Node* Y = createNode(2);
    Y->next = createNode(4);
    Y->next->next = createNode(6);
    Node* Z = mergeLists(X, Y);
    displayList(Z);
    while (Z != NULL) {
        Node* temp = Z;
        Z = Z->next;
        free(temp);
    }
    return 0;
}
