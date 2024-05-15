#include <stdio.h>
typedef struct sparse
{
    int row;
    int col;
    int val;
}sparse;
sparse a[10];
sparse b[10];
void Transpose(sparse a[],sparse b[])
{
    int i,j,k=0;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    for(i=0;i<a[0].col;i++)
    {
        for(j=1;j<=a[0].val;j++)
        {
            if(a[j].col==i)
            {
                k++;
                b[k].row=a[j].col;
                b[k].col=a[j].row;
                b[k].val=a[j].val;
            }
        }
    }
    printf("After Transpose:\n");
    printf("row\tcolumn\tvalue\n");
    for(int i=0;i<=a[0].val;i++)
    printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
}
void main()
{
    int arr[10][10],m,n,k=0;
    printf("Enter number of rows and columns:");
    scanf("%d %d",&m,&n);
    printf("Enter values:");
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    a[0].row=m;
    a[0].col=n;
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                k++;
                a[k].row=i;
                a[k].col=j;
                a[k].val=arr[i][j];
            }
        }
    }
    a[0].val=k;
    printf("row\tcolumn\tvalue\n");
    for(int i=0;i<=a[0].val;i++)
    printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
    Transpose(a,b);
}
