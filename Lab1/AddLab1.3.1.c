#include<stdio.h>
#include<stdlib.h>
int main()
{

    int a[10][10],b[10][10],c[10][10],m,n,p,q,i,j,k;
    printf("enter the number of rows and columns in A:");
    scanf("%d %d",&m,&n);
    printf("enter the number of rows and columns in B:");
    scanf("%d %d",&p,&q);
    if(n!=p)
    {
        printf("Invalid");
        exit(0);
    }
    printf("enter A elements:");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter B elements:");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<q;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("Multiple:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}
