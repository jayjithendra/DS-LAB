
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* llink;
    int data;
    struct node* rlink;
} node;
node* x1 = NULL;
node* x2 = NULL;
node * insert(node* first, int val)
{
    node* cur;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->rlink = NULL;
    temp->llink = NULL;
    if(first==NULL)
    {
        first= temp;
    }
    else
    {
        for(cur=first;cur->rlink!=NULL;cur=cur->rlink);

        cur->rlink = temp;
        temp->llink = cur;
    }
    return first;
}
void display(node* first)
{
    if(first == NULL) printf("Empty List:");
    node* cur;
    for(cur=first;cur!=NULL; cur = cur->rlink) printf("%d ", cur->data);
    printf("\n");
}
int main()
{
    int n1,n2,in;
    printf("Enter number of elements in first list:");
    scanf("%d",&n1);
    printf("Enter values:");
    for(int i = 0;i < n1;i++)
    {
        scanf("%d",&in);
        x1=insert(x1,in);
    }
    display(x1);
    printf("Enter number of elements in second list:");
    scanf("%d",&n2);
    printf("Enter values:");
    for(int i = 0;i < n2;i++)
    {
        scanf("%d",&in);
        x2=insert(x2,in);
    }
    display(x2);
    node* cur;
    for(cur=x1;cur->rlink!=NULL;cur=cur->rlink);
    cur->rlink = x2;
    x2->llink = cur;
    display(x1);
    return 0;
}
