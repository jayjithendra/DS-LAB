#include <stdio.h>
int main()
{
    int i,n,a[50],x,flag,pos;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to find:");
    scanf("%d",&x);
    flag=0;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            pos=i+1;
            flag=1;
        }
    }
    if(flag==1)
        printf("Element found at position:%d",pos);
    else
        printf("Not found");
}
