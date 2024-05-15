#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree * lchild;
    struct tree * rchild;
}tree;
tree * create(void)
{
    tree * root = NULL;
    tree * curr = root;
    tree * prev = NULL;
    int i, n, j;
    printf("Enter number of nodes to be inserted: ");
    scanf("%d", &n);
    char direction[20];
    for(j = 0; j < n; j++)
    {
        tree * temp = (tree *) malloc(sizeof(tree));
        printf("Enter data: ");
        scanf("%d", &temp -> data);
        temp -> lchild = NULL;
        temp -> rchild = NULL;
        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            printf("Enter the direction: ");
            scanf("%s", direction);
            curr = root;
            i = 0;
            while((direction[i] != '\0') && (curr != NULL))
            {
                prev = curr;
                if(direction[i] == 'l')
                {
                    curr = curr -> lchild;
                }
                else
                {
                    curr = curr -> rchild;
                }
                i++;
            }
            if(curr != NULL || direction[i] != '\0')
            {
                printf("Invalid direction\n");
                j--;
            }
            else
            {
                if(direction[i - 1] == 'l')
                {
                    prev -> lchild = temp;
                }
                else if(direction[i - 1] == 'r')
                {
                    prev -> rchild = temp;
                }
                else
                {
                    printf("Invalid input\n");
                    j--;
                }
            }
        }
    }
    return root;
}
int mirror(tree * a, tree * b)
{
    if(a == NULL && b == NULL)
    {
        return 1;
    }
    if(a == NULL || b == NULL)
    {
        return 0;
    }
    if(a -> data != b -> data)
    {
        return 0;
    }
    return mirror(a -> lchild, b -> rchild) && mirror(a -> rchild, b -> lchild);
}
int main(void)
{
    tree * x = create();
    tree * y = create();
    if(mirror(x, y) == 1)
    {
        printf("They are Mirror Trees\n");
    }
    else
    {
        printf("They are not Mirror Trees\n");
    }
}
