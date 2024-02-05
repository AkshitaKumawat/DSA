#include <stdio.h>
#include <stdlib.h>
#include <process.h>

typedef struct treenode
{
    struct treenode *l;
    int data;
    struct treenode *r;
} node;

node *temp, *root;

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->l);
        preorder(root->r);
    }
    else
        printf("Tree does not exist\n");
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->l);
        printf("%d ", root->data);
        inorder(root->r);
    }
    else
        printf("Tree does not exist\n");
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf("%d ", root->data);
    }
    else
        printf("Tree does not exist\n");
}

void create_tree()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter new element: ");
    scanf("%d", &temp->data);
    temp->l = NULL;
    temp->r = NULL;
    if (root == NULL)
        root = temp;
    else
    {
        node *p, *q;
        p = root;

        while (p != NULL)
        {
            if (p->data > temp->data)
            {
                q = p;
                p = p->l;
            }
            else
            {
                q = p;
                p = p->r;
            }
        }
        if (q->data > temp->data)
            q->l = temp;
        else
            q->r = temp;
    }
}

int main()
{
    int n;
    printf("\nEnter 1 for create tree   2 for preorder traversing    3 for inorder    4 for postorder  5  for exit\n");
    while (1)
    {
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            create_tree();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nHave a lovely day!\n");
        }
    }
    return 0;
}