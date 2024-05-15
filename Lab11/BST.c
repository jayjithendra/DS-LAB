#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * lchild;
    struct node * rchild;
};
typedef struct node bst;
bst * root = NULL;
bst * newNode(int item)
{
    bst * temp = (bst*)malloc(sizeof(bst));
    temp->data = item;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
void create()
{
    bst * curr, * prev, * temp;
    int i,n,val;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Data:");
        scanf("%d",&val);
        temp = newNode(val);
        prev = NULL;
        curr = root;
        while(curr != NULL)
        {
            prev = curr;
            if(temp -> data > curr -> data)
                curr = curr -> rchild;
            else if(temp -> data < curr -> data)
                curr = curr -> lchild;
            else
            {
                printf("Not unique");
                i--;
                break;
            }
        }
        if(prev == NULL)
            root = temp;
        else if(temp -> data > prev->data)
            prev -> rchild = temp;
        else
            prev -> lchild = temp;
    }
}
bst * insert(bst * root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root -> data)
        root->lchild = insert(root->lchild, key);
    else if(key > root -> data)
        root->rchild = insert(root->rchild, key);
    else
    {
        printf("Not unique");
        return -999999999;
    }
    return root;
}
bst * search(int key)
{
    bst * curr = root;
    while(curr!=NULL)
    {
        if(curr -> data == key)
            return curr;
        else if (curr -> data < key)
            curr = curr -> rchild;
        else
            curr = curr -> lchild;
    }
    return curr;
}
void inorder(bst * root)
{
    if (root != NULL) {
        inorder(root -> lchild);
        printf("%d\t", root->data);
        inorder(root -> rchild);
    }
}
int main()
{
    create();
    inorder(root);
    bst * found = search(3);
    if(found)
        printf("\nFound\n");
    else
        printf("\nNot found\n");
    bst * a = insert(root,7);
    inorder(root);
}
