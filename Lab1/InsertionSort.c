#include <stdio.h>

int main()
{
    int i,n,j,ele,found=0,a[50];
    printf("Enter size:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        ele=a[i];
        j=i-1;
        while(j>=0&&a[j]>ele)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=ele;
    }
    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
