#include <stdio.h>
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
infix2postfix(char infix[],char postfix[])
{
    int i=0,j=0;
    precedence temp;push('#');
    while (infix[i]!='\0')
    {
        temp = get_token(infix[i]);
        if(temp==operand)
            postfix[j++]=infix[i];
        else if(temp==rparen)
        {
            while (s[top]!='(')
                    postfix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]<=isp[get_token(s[top])])
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(s[top]!='#')
        postfix[j++]=pop();
}
void main()
{
    int i;
    char infix[20],postfix[20];
    printf("Enter expression:");
    scanf("%s",infix);
    infix2postfix(infix,postfix);
    printf("postfix form:%s",postfix);
}
