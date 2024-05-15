void main()
{
    int mag[10][10],i,j,row,col,rowsum[10],colsum[10];
    int pd=0,sd=0,k,x=0,b[100];
    printf("enter dimension:\n");
    scanf("%d %d",&row,&col);
    if(row!=col)
    {
        printf("matrix is not a magic square square");
        exit(0);
    }
    printf("enter elements for A:");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            scanf("%d",&mag[i][j]);
    }
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            b[x++]=mag[i][j];
            for(k=0; k<x-1; k++)
            {
                for(j=k+1; j<x; j++)
                {
                    if(b[k]==b[j])
                    {
                        printf("elements are not distinct\n");
                        printf("matrix is not a magic square");
                        exit(0);
                    }
                }
            }
        }

    }
    for(i=0; i<row; i++)
        pd=pd + mag[i][i];
    for(i=0; i<row; i++)
    {
        rowsum[i]=0;
        for(j=0;j< col; j++)
            rowsum[i]=rowsum[i]+mag[i][j];
        if(rowsum[i]!=pd)
        {
            printf("matrix is not a magic square");
            exit(0);
        }
    }
    for(i=0;i<col;i++)
    {
        colsum[i]=0;
        for(j=0;j<row;j++)
            colsum[i]=colsum[i]+mag[j][i];
        if(colsum[i]!=pd)
        {
            printf("matrix is not a magic square");
            exit(0);
        }
    }
    i=row-1;
    k=i;
    for(j=col-1;j>=0;j--,i--)
        sd=sd+mag[i][k-j];
    if(sd!=pd)
    {
        printf("matrix is not a magic square");
        exit(0);
    }
    printf("Matrix is a magic square");
}
