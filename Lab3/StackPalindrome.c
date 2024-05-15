#include <stdio.h>
#include <string.h>
int top=-1,size=10;
char stack[10];
void Push(char a)
{
    if(top==size-1)
        printf("OverFlow");
    else
        stack[++top]=a;
}
char pop()
{
    if (top==-1)
        printf("UnderFlow");
    else
        return(stack[top--]);
}

int main()
{
    char s[10],rev[10];
    printf("Enter word:");
    scanf("%s",&s);
    int i,j;
    for(i=0;s[i]!='\0';i++)
        Push(s[i]);
    for(j=0;j<i;j++)
        rev[j]=pop();
    rev[j]='\0';
    if(strcmp(rev,stack)==0)
        printf("Palindrome");
    else
        printf("Not a palindrome");
}
