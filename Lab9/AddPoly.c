#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coef;
    int exp;
    struct node * next;
}node;
node * create(int c, int e, node * ptr)
{
    node * temp = (node *) malloc(sizeof(node));
    temp -> coef = c;
    temp -> exp = e;
    temp -> next = ptr;
    return(temp);
}
node * create_poly(int n)
{
    node * first = NULL;
    int i, c, e;
    node * rear = NULL;
    for(i = 0; i < n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%d", &c);
        printf("Enter exponent: ");
        scanf("%d", &e);
        if(first == NULL)
        {
            first = create(c, e, NULL);
            rear = first;
        }
        else
        {
            rear -> next = create(c, e, NULL);
            rear = rear -> next;
        }
    }
    return first;
}
node * add(node * a, node * b)
{
    node * front, * rear, * temp;
    rear = front = create(0, 0, NULL);

    while((a != NULL) && (b != NULL))
    {
        if(a -> exp == b -> exp)
        {
            if((a -> coef) + (b -> coef))
            {
                rear = rear -> next = create((a -> coef + b -> coef), a -> exp, NULL);
            }
            a = a -> next;
            b = b -> next;
        }
        else if(a -> exp > b -> exp)
        {
            rear = rear -> next = create(a -> coef, a -> exp, NULL);
            a = a -> next;
        }
        else
        {
            rear = rear -> next = create(b -> coef, b -> exp, NULL);
            b = b -> next;
        }
    }
    while(b != NULL)
    {
        rear = rear -> next = create(b -> coef, b -> exp, NULL);
        b = b -> next;
    }
    while(a != NULL)
    {
        rear = rear -> next = create(a -> coef, a -> exp, NULL);
        a = a -> next;
    }
    temp = front;
    front = front -> next;
    free(temp);
    return front;
}
void disp(node * x)
{
    while(x != NULL)
    {
        printf("%dx^%d\t", x -> coef, x -> exp);
        x = x -> next;
        if(x != NULL)
        {
            printf("+\t");
        }
    }
    printf("\n");
}
int main(void)
{
    int n1, n2;
    printf("Enter number of terms in polynomial a: ");
    scanf("%d", &n1);
    printf("Enter polynomial : \n");
    node * a = create_poly(n1);
    printf("Enter number of terms in polynomial b: ");
    scanf("%d", &n2);
    printf("Enter polynomial : \n");
    node * b = create_poly(n2);
    node * c = add(a, b);
    disp(c);
}
