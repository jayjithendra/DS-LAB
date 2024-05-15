#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node * leftlink;
    int data;
    struct node * rightlink;
}node;

node * first = NULL;

node * create(node * prev, int ele, node * next)
{
    node * temp = (node *)malloc(sizeof(node));
    temp -> rightlink = next;
    temp -> data = ele;
    temp -> leftlink = prev;
    return(temp);
}

void create_dll(int n)
{
    int i, ele;
    node * last;

    for(i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &ele);

        if(first == NULL)
        {
            first = last = create(NULL, ele, NULL);
        }

        else
        {
            last -> rightlink = create(last, ele, NULL);
            last = last -> rightlink;
        }
    }
}

void disp(void)
{
    node * curr;

    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        for(curr = first; curr != NULL; curr = curr -> rightlink)
        {
            printf("%d\t", curr -> data);
        }
        printf("\n");
    }
}

void rev(void)
{
    node * curr;
    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        for(curr = first; curr -> rightlink != NULL; curr = curr -> rightlink);
        for(; curr != NULL; curr = curr -> leftlink)
        {
            printf("%d\t", curr -> data);
        }
        printf("\n");
    }
}

int delete_rear()
{
    int a;
    if(first == NULL)
    {
        printf("List is empty\n");
        return -99999;
    }

    else
    {
        node * curr;
        for(curr = first; curr -> rightlink != NULL; curr = curr -> rightlink);
        a = curr -> data;
        node * temp = curr;
        curr = curr -> leftlink;
        curr -> rightlink = NULL;
        free(temp);
        return a;
    }
}

void insert_last(int ele)
{
    if(first == NULL)
    {
       first = create(NULL, ele, NULL);
    }

    else
    {
        node * curr;
        for(curr = first; curr -> rightlink != NULL; curr = curr -> rightlink);
        curr -> rightlink = create(curr, ele, NULL);
    }
}

void insert_pos(int ele, int pos)
{
    int i = 1;
    node * curr = first;
    if(pos == 1)
    {
        first = create(NULL, ele, curr);
    }

    else
    {
        //you go to the position before the given
        for(curr = first; i < pos - 1; i++, curr = curr -> rightlink);
        curr -> rightlink = create(curr, ele, curr -> rightlink);
    }
}

int del_pos(int pos)
{
    int a, i = 0;
    node * curr = first;

    if(first == NULL)
    {
        printf("List is empty");
        return -99999;
    }

    else
    {
        //go to the position where you want to delete
        for(curr = first; i < pos - 1; i++, curr = curr -> rightlink);
        if(curr == NULL)
        {
            printf("No element found in the given position");
            return -99999;
        }

        else
        {
            if(curr == first)
            {
                node * temp = curr;
                curr = curr -> rightlink;
                first = curr;
                curr -> leftlink = NULL;
                a = temp -> data;
                free(temp);
                return a;
            }

            else
            {
                node * temp = curr;
                a = temp -> data;
                curr -> leftlink -> rightlink = curr -> rightlink;
                if(curr -> rightlink != NULL)
                {
                    curr -> rightlink -> leftlink = curr -> leftlink;
                }
                free(temp);
                return a;
            }
        }
    }
}

void insert_after(int ele, int bdata)
{
    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        node * curr = first;
        int flag = 0;
        for(curr = first; curr != NULL; curr = curr -> rightlink)
        {
            if(curr -> data == bdata)
            {
                flag = 1;
                if(curr -> rightlink != NULL)
                {
                    curr -> rightlink = create(curr, ele, curr -> rightlink);
                    curr = curr -> rightlink;
                    curr -> rightlink -> leftlink = curr;
                }

                else
                {
                    curr -> rightlink = create(curr, ele, NULL);
                }

                break;
            }
        }

        if(!flag)
        {
            printf("Element not found\n");
        }
    }
}

void insert_before(int ele, int adata)
{

    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        node * curr = first;
        int flag = 0;

        for(curr = first; curr != NULL; curr = curr -> rightlink)
        {
            if(curr -> data == adata)
            {
                flag = 1;
                if(curr == first)
                {
                    curr -> leftlink = create(NULL, ele, curr);
                    first = curr -> leftlink;
                    break;
                }

                else
                {
                    //go to 1 position previous
                    curr = curr -> leftlink;
                    curr -> rightlink = create(curr, ele, curr -> rightlink);
                    curr = curr -> rightlink;
                    curr -> rightlink -> leftlink = curr;
                    break;
                }
            }
        }

        if(!flag)
        {
            printf("Element not found\n");
        }
    }
}



int main(void)
{
    int key, opt, ele;

    do
    {
        printf("Enter 0 to create a linked list of n nodes\nEnter 1 to insert an element at the rear end of the list\nEnter 2 to delete an element from the rear end of list\nEnter 3 to insert an element at the given position of the list\nEnter 4 to delete an element from a given position of the list\nEnter 5 to insert an element after another element\nEnter 6 to insert an element before another element\nEnter 7 to traverse the list\nEnter 8 to reverse the list\nEnter 9 to exit\n");
        printf("Enter option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                insert_last(ele);
                disp();
                break;

            case 2:
                ele = delete_rear();
                if(ele != -99999)
                {
                    printf("Deleted element is : %d\n", ele);
                }
                disp();
                break;

            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                printf("Enter position at which element has to be inserted: ");
                scanf("%d", &key);
                insert_pos(ele, key);
                disp();
                break;

            case 4:
                printf("Enter position at which element has to be deleted: ");
                scanf("%d", &key);
                ele = del_pos(key);
                if(ele != -99999)
                {
                    printf("Deleted element is : %d\n", ele);
                }
                disp();
                break;

            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                printf("Enter element after which new element has to be inserted: ");
                scanf("%d", &key);
                insert_after(ele, key);
                disp();
                break;

            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                printf("Enter element before which new element has to be inserted: ");
                scanf("%d", &key);
                insert_before(ele, key);
                disp();
                break;

            case 7:
                printf("Traversing and displaying all the elements in the list\n");
                disp();
                break;

            case 8:
                rev();
                break;

            case 0:
                printf("Enter number of elements :");
                scanf("%d", &ele);
                create_dll(ele);
                disp();
                break;

            case 9:
                printf("Exiting the program\n");
        }
    }
    while(opt != 9);
}
