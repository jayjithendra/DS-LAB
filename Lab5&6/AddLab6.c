#include <stdio.h>
#include <string.h>
char s[20][20];
int top=-1;
void push1(char a[])
{
    if(top==19)
        printf("OverFlow");
    else
        strcpy(s[++top],a);
}
char *pop1()
{
    if (top==-1)
        printf("UnderFlow");
    else
        return(s[top--]);
}
typedef enum {lparen,rparen,plus,minus,times,division,mod,cos,operand}precedence;
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
void prefix2infix(char prefix[],int n)
{
    char temp1[20],temp2[20],op1[20],op2[20];
    precedence temp;
    int i=n-1;
    while(i>=0)
    {
        temp=get_token(prefix[i]);
        temp1[0]=prefix[i];
        temp1[1]='\0';
        if(temp==operand)
            push1(temp1);
        else
        {
            strcpy(op1,pop1());
            strcpy(op2,pop1());
            strcpy(temp2,"(");
            strcat(temp2,op1);
            strcat(temp2,temp1);
            strcat(temp2,op2);
            strcat(temp2,")");
            push1(temp2);
        }
        i--;
    }
}
char s1[20];
int top1=-1;
void push(char a)
{
    if(top1==19)
        printf("OverFlow");
    else
        s1[++top1]=a;
}
char pop()
{
    if (top1==-1)
        printf("UnderFlow");
    else
        return(s1[top1--]);
}
int isp[]={0,19,12,12,13,13,13,0,0};
int icp[]={20,19,12,12,13,13,13,0,0};
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
            while (s1[top1]!='(')
                    postfix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]<=isp[get_token(s1[top1])])
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(s1[top1]!='#')
        postfix[j++]=pop();
}
void main()
{
    int n;
    char prefix[20],postfix[20];
    printf("Enter expression:");
    scanf("%s",&prefix);
    n=strlen(prefix);
    prefix2infix(prefix,n);
    infix2postfix(s,postfix);
    puts(postfix);
}
