#include<stdio.h>
typedef struct sparse
{
    int row;
    int col;
    int val;
}sparse;
sparse a[10];
sparse b[10];
void FastTrans(sparse a[10],sparse b[10])
{
    int non_zero[10]={0},starting_pos[10];
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    for(int i=1;i<=a[0].val;i++)
        non_zero[a[i].col]++;
    starting_pos[0]=1;
    for(int i=1;i<b[0].row;i++)
        starting_pos[i]=starting_pos[i-1]+non_zero[i-1];
    for(int i=1;i<=a[0].val;i++)
    {
        int j=starting_pos[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;
    }
    printf("After Fast Transpose:\n");
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
    FastTrans(a,b);
}
