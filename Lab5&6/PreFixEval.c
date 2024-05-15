#include <stdio.h>
#include <string.h>
char s[20];
int top=-1;
void push(char a)
{
    if(top==19)
        printf("OverFlow");
    else
        s[++top]=a;
}
char pop()
{
    if (top==-1)
        printf("UnderFlow");
    else
        return(s[top--]);
}
void prefix_eval(char prefix[],int n)
{
    int i=n-1,op1,op2;
    while (i>=0)
    {
        if(prefix[i]>='0' && prefix[i]<='9')
            push(prefix[i]-'0');
        else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/'||prefix[i]=='%')
        {
            op1=pop();
            op2=pop();
        switch(prefix[i])
        {
        case '+':
            push(op1+op2);
            break;
        case '-':
            push(op1-op2);
            break;
        case '*':
            push(op1*op2);
            break;
        case '/':
            push(op1/op2);
            break;
        case '%':
            push(op1%op2);
            break;
        }
        }
        else
        {
            printf("invalid.");
            exit(0);
        }
        i--;
    }
    printf("result=%d",pop());
}
void main()
{
    int n;
    char prefix[20];
    printf("Enter expression:");
    scanf("%s",prefix);
    n=strlen(prefix);
    prefix_eval(prefix,n);
}
