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
int depth(tree * ptr)
{
    int rdepth = 0, ldepth = 0;
    if(ptr == NULL)
    {
        return 0;
    }
    else
    {
        ldepth = depth(ptr -> lchild);
        rdepth = depth(ptr -> rchild);
        if(ldepth > rdepth)
        {
            return(ldepth + 1);
        }
        else
        {
            return(rdepth + 1);
        }
    }
}
int leaf(tree * root)
{
    tree * curr = root;
    tree * queue[20];
    int front = -1, rear = -1, leaf = 0;
    queue[++rear] = curr;
    while(front != rear)
    {
        curr = queue[++front];
        if(curr -> lchild != NULL)
        {
            queue[++rear] = curr -> lchild;
        }
        if(curr -> rchild != NULL)
        {
            queue[++rear] = curr -> rchild;
        }
        if(curr -> lchild == NULL && curr -> rchild == NULL)
        {
            leaf++;
        }
    }
    return leaf;
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
void preorder(tree * root)
{
    tree * curr = root;
    tree * stack[20];
    int top = -1;
    for(;;)
    {
        while(curr != NULL)
        {
            printf("%d\t", curr -> data);
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
        curr = curr -> rchild;
    }
    printf("\n");
}
int parent(tree * root, int ele)
{
    if (root == NULL)
    {
        return -99999;
    }
    if ((root -> lchild != NULL && root -> lchild -> data == ele) || (root -> rchild != NULL && root -> rchild -> data == ele))
    {
        return root->data;
    }
    int leftParent = parent(root->lchild, ele);
    if (leftParent != -99999)
    {
        return leftParent;
    }
    return parent(root->rchild, ele);
}
void postorder(tree * root)
{
    tree * stack[100];
    tree * curr = root;
    tree * temp = NULL;
    int top = -1;
    for(;;)
    {
        while(curr != NULL)
        {
            if(curr -> rchild != NULL)
            {
                stack[++top] = curr -> rchild;
            }
            stack[++top] = curr;
            curr = curr -> lchild;
        }
        curr = stack[top--];
        if((curr -> rchild != NULL) && (stack[top] == curr -> rchild))
        {
            top--;
            stack[++top] = curr;
            curr = curr -> rchild;
        }
        else
        {
            printf("%d\t", curr -> data);
            curr = NULL;
        }
        if(top == - 1)
        {
            break;
        }
    }
}
void ancestor(tree * root, int a)
{
    printf("Ancestors of %d: ", a);
    while (a != root -> data)
    {
        printf("%d\t", parent(root, a));
        a = parent(root, a);
    }
    printf("\n");
}
int main(void)
{
    printf("Creating a Binary Tree\n");
    tree * a = create();
    int opt, ele;
    do
    {
        printf("Enter 1 to do in order traversal\nEnter 2 to do postorder traversal\nEnter 3 to do preorder traversal\nEnter 4 to print the parent of the given element\nEnter 5 to print the depth of the tree\nEnter 6 to print the ancestors of a given element\nEnter 7 to count the leaf nodes in a binary tree\nEnter 8 to exit\n");
        printf("Enter option: ");
        scanf("%d", &opt);
       switch(opt)
       {
        case 1:
            inorder(a);
            break;
        case 2:
            postorder(a);
            printf("\n");
            break;
        case 3:
            preorder(a);
            break;
        case 4:
            printf("Enter element whose parent is to be found: ");
            scanf("%d", &ele);
            if(parent(a, ele) != -99999)
            {
                printf("parent element is : %d\n", parent(a, ele));
            }
            break;
        case 5:
            printf("Depth of tree is : %d\n", depth(a));
            break;
        case 6:
            printf("Enter element whose ancestors is to be found: ");
            scanf("%d", &ele);
            ancestor(a, ele);
            break;
        case 7:
            printf("Number of leaf nodes : %d\n", leaf(a));
            break;
        case 8:
            break;
       }
    }
    while(opt != 8);
}
