#include<stdio.h>
void main()
{
    int a[10],b[10],c[2],m,n;
    printf("Enter number of elements in A and B:");
    scanf("%d %d",&m,&n);
    printf("Enter elements in A:");
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    printf("Enter elements in B:");
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int largeA=a[0];
    int largeB=b[0];
    for(int i=1;i<m;i++)
    {
        if(a[i]>largeA)
            largeA=a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(b[i]>largeB)
            largeB=b[i];
    }
    c[0]=largeA;
    c[1]=largeB;
    printf("C:%d\t%d",c[0],c[1]);
}
