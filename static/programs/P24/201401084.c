#include <stdio.h>

#include <stdlib.h>


typedef struct linklist
{
    int leftchild;
    int height;
    int d;
    struct linklist *left;
    struct linklist *right;
}node;


int top;
int count;
int stack[200005];


node *rightrotate(node *x)
{
    node *y=x->left;
    x->leftchild=x->leftchild-y->leftchild-1;
    x->left=y->right;
    y->right=x;
    if(height(x->left)>height(x->right))
        x->height=height(x->left)+1;
    else
        x->height=height(x->right)+1;
    if(height(y->left)>height(y->right))
        y->height=height(y->left)+1;
    else
        y->height=height(y->right)+1;
    return y;
}


node *leftrotate(node *x)
{
    node *y=x->right;
    y->leftchild=y->leftchild+x->leftchild+1;
    x->right=y->left;
    y->left=x;
    if(height(x->left)>height(x->right))
        x->height=height(x->left)+1;
    else
        x->height=height(x->right)+1;
    if(height(y->left)>height(y->right))
        y->height=height(y->left)+1;
    else
        y->height=height(y->right)+1;
    return y;
}



int height(node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}



node *insert(node *root,int v)
{
    if(root==NULL)
    {
        node *p=(node *)malloc(sizeof(node));
        p->d=v;
        p->left=NULL;
        p->right=NULL;
        p->height=1;
        p->leftchild=0;
        root=p;
    }
    else if(v<=root->d)
    {
        root->leftchild=root->leftchild+1;
        root->left=insert(root->left,v);
    }
    else if(v>root->d)
    {
        root->right=insert(root->right,v);
    }
    if(height(root->left)>height(root->right))
        root->height=height(root->left)+1;
    else
        root->height=height(root->right)+1;
    int balancefactor=height(root->left)-height(root->right);
    if(balancefactor>1)
    {
        int bf=height(root->left->left)-height(root->left->right);
        if(bf==1)
        {
            return rightrotate(root);
        }
        else if(bf==-1)
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }			

    }
    else if(balancefactor<-1)
    {
        int bf=height(root->right->left)-height(root->right->right);
        if(bf==-1)
            return leftrotate(root);
        else if(bf==1)
        {
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
    }
    return root;
}


void preorder(node *root)
{
    if(root==NULL)
        return;
    printf("root->d=%d root->leftchild=%d\n",root->d,root->leftchild);
    preorder(root->left);
    preorder(root->right);
}


void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    stack[++top]=root->d;
    inorder(root->right);
}


int inorder1(node *root,int x)
{
    if(root==NULL)
        return 0;
    if(root->leftchild+1==x)
    {
        printf("%d\n",root->d);
        return 1;
    }
    else if(root->leftchild+1<x)
    {
        int y=inorder1(root->right,x-(root->leftchild+1));
        if(y==1)
            return 1;
    }
    else
    {
        int y=inorder1(root->left,x);
        if(y==1)
            return 1;
    }
}


int search(node *root,int x)
{
    if(root==NULL)
        return 0;
    if(root->d==x)
        return 1;
    else if(x<root->d)
        search(root->left,x);
    else
        search(root->right,x);
}



void search1(node *root,int x)
{
    if(root==NULL)
        return;
    if(root->d==x)
    {
        count=count+root->leftchild;
        return;
    }
    else if(x<root->d)
    {
        search1(root->left,x);
    }
    else
    {
        count=count+root->leftchild+1;
        search1(root->right,x);
    }
}



int main()
{
    node *root=NULL;
    int i;
    int n;
    char stringp[100];
    for(;;)
    {
        int x;
        scanf("%s",stringp);
        if(stringp[0]=='Q')
            break;
        else if(stringp[0]=='S')
        {
            count=0;
            scanf("%d",&x);
            root=insert(root,x);
        }
        else if(stringp[0]=='C')
        {
            scanf("%d",&x);
            int y=search(root,x);
            if(y==0)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else if(stringp[0]=='H')
        {
            scanf("%d",&x);
            int y=inorder1(root,x);
            if(y==0)
                printf("NONE\n");
        }
        else if(stringp[0]=='R')
        {
            scanf("%d",&x);
            count=0;
            search1(root,x);
            printf("%d\n",count);
        }
   	   // preorder(root);
       // printf("\n\n");
    }
    return 0;
}

