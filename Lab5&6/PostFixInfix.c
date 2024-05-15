#include <stdio.h>
#include <string.h>
char s[20][20];
int top=-1;
void push(char a[])
{
    if(top==19)
        printf("OverFlow");
    else
        strcpy(s[++top],a);
}
char *pop()
{
    if (top==-1)
        printf("UnderFlow");
    else
        return(s[top--]);
}
typedef enum {lparen,rparen,plus,minus,times,division,mod,cos,operand}precedence;
int isp[]={0,19,12,12,13,13,13,0,0};
int icp[]={20,19,12,12,13,13,13,0,0};
get_token(char c)
{
    switch(c)
    {
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '*':return times;
        case '/':return division;
        case '%':return mod;
        case '#':return cos;
        default: return operand;
    }
}
void postfix2infix(char postfix[])
{
    char temp1[20],temp2[20],op1[20],op2[20];
    precedence temp;
    int i=0;
    while(postfix[i]!='\0')
    {
        temp=get_token(postfix[i]);
        temp1[0]=postfix[i];
        temp1[1]='\0';
        if(temp==operand)
            push(temp1);
        else
        {
            strcpy(op2,pop());
            strcpy(op1,pop());
            strcpy(temp2,"(");
            strcat(temp2,op1);
            strcat(temp2,temp1);
            strcat(temp2,op2);
            strcat(temp2,")");
            push(temp2);
        }
        i++;
    }
}
void main()
{
    char postfix[20];
    printf("Enter expression:");
    scanf("%s",postfix);
    postfix2infix(postfix);
    puts(s);
}
