#include <stdio.h>
int main()
{
    int i,n,a[50],j,temp,smallest,index;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        smallest=a[i];
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<=smallest)
            {
                smallest=a[j];
                index=j;
            }
        }
        a[index]=a[i];
        a[i]=smallest;
    }
    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
