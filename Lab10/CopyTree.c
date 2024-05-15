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
tree * copy(tree * root)
{
    if (root == NULL)
    {
        return NULL;
    }
    // Create a new node with the same data as the original node
    tree * first = (tree *)malloc(sizeof(tree));
    first -> data = root -> data;
    first -> lchild = copy(root -> lchild); // Recursively copy the left subtree
    first -> rchild = copy(root -> rchild); // Recursively copy the right subtree

    return first;
}
void inorder(tree * root)
{
    tree * curr = root;
    tree * stack[20];
    int top = -1;
    for(;;)
    {
        while(curr != NULL)
        {
            stack[++top] = curr;
            curr = curr -> lchild;
        }
        if(top > -1)
        {
            curr = stack[top--];
        }
        else
        {
            break;
        }
        printf("%d\t", curr -> data);
        curr = curr -> rchild;
    }
    printf("\n");
}
int main(void)
{
    tree * a = create();
    tree * b = copy(a);
    printf("\nInorder traversal of copied string:\n");
    inorder(b);
}

