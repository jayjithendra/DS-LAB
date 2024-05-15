#include <stdio.h>
#include <string.h>
char s[20];
int top=-1;
char rev[20];
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
int isp[]={19,0,12,12,13,13,13,0,0};
int icp[]={19,20,12,12,13,13,13,0,0};
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
infix2prefix(char infix[],char prefix[],int n)
{
    strrev(infix);
    int i=0,j=0;
    precedence temp;push('#');
    while (infix[i]!='\0')
    {
        temp = get_token(infix[i]);
        if(temp==operand)
            prefix[j++]=infix[i];
        else if(temp==lparen)
        {
            while (s[top]!=')')
                    prefix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]<isp[get_token(s[top])])
                prefix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(s[top]!='#')
        prefix[j++]=pop();
    strrev(prefix);
}
void main()
{
    int i,n;
    char infix[20],prefix[20];
    printf("Enter expression:");
    scanf("%s",infix);
    n=strlen(infix);
    infix2prefix(infix,prefix,n);
    printf("prefix form:%s",prefix);
}
