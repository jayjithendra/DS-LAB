#include <stdio.h>
int product(int a,int b)
{
    if (a<b)
    {
        return product(b,a);
    }
    else if (b!=0)
    {
        return (a+product(a,b-1));
    }
    else
    {
        return 0;
    }
}
void main()
{
    int a,b,result;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    result=product(a,b);
    printf("Product:%d",result);
}

