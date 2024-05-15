#include<stdio.h>
int front=0,rear=0,max=5,a[5];
void insert(int ele)
{
    if((rear+1)%max==front)
        printf("Q is full.");
    else
    {
        rear=(rear+1)%max;
        a[rear]=ele;
    }
}
int del()
{
    if(front==rear)
    {
        printf("Q is empty.");
        return(-9999);
    }
    else
    {
        front=(front+1)%max;
        return(a[front]);
    }
}
void display()
{
    if(front==rear)
    {
        printf("Q is empty.");
    }
    else
    {
        for(int i=(front+1)%max;i!=(rear+1)%max;i=(i+1)%max)
            printf("%d\t",a[i]);
        printf("\n");
    }
}
int main()
{
    int n,i,x,m=1;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&x);
            insert(x);
            break;
        case 2:
            printf("Element deleted=%d\n",del());
            break;
        case 3:
            printf("The elements are:\n");
            display();
            break;
        case 4:
            m=0;
            break;
        default:
            printf("invalid choice");
    }
}while(m!=0);
}
