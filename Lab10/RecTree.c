#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree* lchild;
    struct tree* rchild;
} tree;
tree * create(int data)
{
    tree * temp = (tree*)malloc(sizeof(tree));
    temp -> data = data;
    temp -> lchild = NULL;
    temp -> rchild = NULL;
    return temp;
}
tree * createBinaryTree(void)
{
    int data;
    printf("Enter data (or -1 for a NULL node): ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    tree * root = create(data);
    printf("Enter lchild of %d:\n", data);
    root -> lchild = createBinaryTree();
    printf("Enter rchild of %d:\n", data);
    root -> rchild = createBinaryTree();
    return root;
}
void printInorder(tree * root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root -> lchild);
    printf("%d\t", root -> data);
    printInorder(root -> rchild);
}
void printPreorder(tree * root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\t", root -> data);
    printPreorder(root -> lchild);
    printPreorder(root -> rchild);
}
void printPostorder(tree * root)
{
    if(root == NULL)
    {
        return;
    }
    printPostorder(root -> lchild);
    printPostorder(root -> rchild);
    printf("%d\t", root -> data);
}
int main(void)
{
    tree* root = createBinaryTree();
    printf("Inorder traversal of the binary tree:\n");
    printInorder(root);
    printf("\n");
    printf("Preorder traversal of binary tree: \n");
    printPreorder(root);
    printf("\n");
    printf("Postorder traversal of binary tree: \n");
    printPostorder(root);
    printf("\n");
}

