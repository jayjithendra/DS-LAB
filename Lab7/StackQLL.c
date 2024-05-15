#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* top;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void initializeStack(struct Stack* stack)
{
    stack->top = NULL;
}
int isStackEmpty(struct Stack* stack)
{
    return stack->top == NULL;
}
void push(struct Stack* stack, int value)
{
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}
int pop(struct Stack* stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}
void initializeQueue(struct Queue* queue)
{
    queue->front = queue->rear = NULL;
}
int isQueueEmpty(struct Queue* queue)
{
    return queue->front == NULL;
}
void enqueue(struct Queue* queue, int value)
{
    struct Node* newNode = createNode(value);
    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", value);
}
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue))
    {
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}
void display(struct Node* topOrFront, const char* title)
{
    printf("%s: ", title);
    while (topOrFront != NULL) {
        printf("%d ", topOrFront->data);
        topOrFront = topOrFront->next;
    }
    printf("\n");
}
int main()
{
    struct Stack stack;
    struct Queue queue;
    initializeStack(&stack);
    initializeQueue(&queue);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    display(stack.top, "Stack");
    display(queue.front, "Queue");
    int poppedValue1 = pop(&stack);
    int poppedValue2 = pop(&stack);
    int dequeuedValue1 = dequeue(&queue);
    int dequeuedValue2 = dequeue(&queue);
    display(stack.top, "Stack");
    display(queue.front, "Queue");
    return 0;
}
