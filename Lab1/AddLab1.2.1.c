#include<stdio.h>
#include <stdio.h>
int binarysearch(int arr[],int l,int n,int x)
{
    if (n>=l)
    {
        int mid = l+(n-l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid]>x)
            return binarysearch(arr,l,mid-1,x);
        return binarysearch(arr, mid+1,n,x);
    }
    return -1;
}
int main(void)
{
    int a[10],i,n,x;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be found:");
    scanf("%d",&x);
    int result=binarysearch(a,0,n-1,x);
    if(result==-1)
        printf("Element not found");
    else
        printf("Element found at:%d",result+1);
}
