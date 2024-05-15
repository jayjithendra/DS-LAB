#include <stdio.h>
int main()
{
    int i,n,a[50],x,mid,high,low,flag,pos;
    printf("Enter number of elements:");
    scanf("%d",&n);
    high=n-1;
    low=0;
    printf("Enter elements in ascending order:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to find:");
    scanf("%d",&x);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x==a[mid])
        {
            flag=1;
            pos=mid+1;
            break;
        }
        else if(x<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if(flag==1)
        printf("Element found at position:%d",pos);
    else
        printf("Not found");
}
