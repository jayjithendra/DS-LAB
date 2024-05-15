#include <stdio.h>
int StrLen(char s[])
{
    int i;
    for (i=0;s[i]!='\0';i++);
    return (i);
}
void StrConcat(char a[],char b[])
{
    int i,len1,len2;
    len1=StrLen(a);
    len2=StrLen(b);
    for(i=0;i<=len2;i++)
    {
        a[len1+i]=b[i];
    }
}
int StrComp(char a[],char b[])
{
    int i,flag=1,len1,len2;
    len1=StrLen(a);
    len2=StrLen(b);
    if(len1!=len2)
        flag=0;
    for(i=0;i<=len1;i++)
    {
        if(a[i]!=b[i])
        {
            flag=0;
            break;
        }
    }
    if (flag==1)
        printf("Strings are the same.");
    else
        printf("Strings are not the same");
    return(0);
}
void StrInsert (char a[],char b[],int pos)
{
    int i,len1,len2;
    len1=StrLen(a);
    len2=StrLen(b);
    for(i=len1;i>=pos;i--)
        a[i+len2]=a[i];
    for(i=0;i<len2;i++)
        a[pos+i]=b[i];
}
void StrDelete (char a[],char b[])
{
    int i,j,len1,len2,pos;
    len1=StrLen(a);
    len2=StrLen(b);
    for(i=0;i<len1;i++)
    {
        if(a[i]==b[0])
        {
            for(j=0;j<len2+1;j++)
            {
                if (b[j]!=a[i+j])
                    break;
                if(j+1==len2)
                    pos=i;
            }
        }
    }
        for(i=pos;i<len1-len2;i++)
        {
            a[i]=a[i+len2];
        }
        a[len1-len2]='\0';
}

int main()
{
    int n,pos;
    char a[50],b[50];
    printf("1.String length\n 2.String Concatenation\n 3.String Compare\n 4.String Insert\n 5.String Delete\n Enter choice:");
    scanf("%d",&n);
    fflush(stdin);
    switch(n)
    {
    case 1:
        printf("Enter string:");
        gets(a);
        printf("String length=%d",StrLen(a));
        break;
    case 2:
        printf("Enter string1:");
        gets(a);
        printf("Enter string2:");
        gets(b);
        StrConcat(a,b);
        puts(a);
        break;
    case 3:
        printf("Enter string1:");
        gets(a);
        printf("Enter string2:");
        gets(b);
        StrComp(a,b);
        break;
    case 4:
        printf("Enter string1:");
        gets(a);
        printf("Enter string2:");
        gets(b);
        printf("Enter Position:");
        scanf("%d",&pos);
        StrInsert(a,b,pos);
        puts(a);
        break;
    case 5:
        printf("Enter string1:");
        gets(a);
        printf("Enter string2:");
        gets(b);
        StrDelete(a,b);
        puts(a);
        break;
    }
}
