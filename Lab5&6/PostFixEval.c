#include <stdio.h>
#include <stdlib.h>
int s[20];
int top=-1;
void push(int a)
{
    if(top==19)
        printf("OverFlow");
    else
        s[++top]=a;
}
int pop()
{
    if (top==-1)
        printf("UnderFlow");
    else
        return(s[top--]);
}
void postfix_eval(char postfix[])
{
    int i=0,op1,op2;
    while (postfix[i]!='\0')
    {
        if(postfix[i]>='0' && postfix[i]<='9')
            push(postfix[i]-'0');
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='%')
        {
            op2=pop();
            op1=pop();
            switch(postfix[i])
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
        i++;
    }
    printf("result=%d",pop());
}
void main()
{
    char postfix[20];
    printf("Enter expression:");
    scanf("%s",postfix);
    postfix_eval(postfix);
}
