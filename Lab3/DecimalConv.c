#include <stdio.h>
int top=-1,size=50;
char stack[50];
void push(char a)
{
    if (top==size-1)
        printf("Overflow");
    else
        stack[++top]=a;
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
        printf("%c",stack[i]);
}
int main()
{
    int n,b,rem;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Enter base:");
    scanf("%d",&b);
    if(b==2||b==8)
    {
        while(n>0)
        {
            push(n%b+48);
            n=n/b;
        }
        display();
    }
    else
    {
        while(n>0)
        {
            if(n%b<=9)
                push(n%b+48);
            else
                push(n%b+55);
            n=n/b;
        }
        display();
    }
}
