#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* newNode(int data)
{
    node* node = (struct node*)malloc(sizeof(node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int search(int *arr,int start,int end,int value)
{
    int i;
    for(i = start;i <= end;i++)
    {
        if(arr[i] == value)
        return i;
    }
}

int preindex = 0;
    
node* buildTree(int *in,int *pre,int start,int end)
{
    if(end<start)
        return NULL;

    node *temp = newNode(pre[preindex++]);
    if(start == end)
        return temp;

    int index = search(in,start,end,temp->data);
    temp->left = buildTree(in,pre,start,index - 1);
    temp->right = buildTree(in,pre,index + 1,end);

    return temp;
}

void inorder(node *temp)
{
    if (temp!=NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

node *findlca(node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
 
    if (root->data == n1 || root->data == n2)
        return root;
 
    node *leftlca  = findlca(root->left, n1, n2);
    node *rightlca = findlca(root->right, n1, n2);
 
    if(leftlca && rightlca)
        return root;
 
    if(leftlca != NULL)
        return leftlca;
    else 
        return rightlca;
}

int main()
{
    int len;
    scanf("%d",&len);
    int in[1000001],pre[1000001],i;
  
    for(i = 0;i < len;i++)
        scanf("%d", &pre[i]);
    for(i = 0;i < len;i++)
        scanf("%d", &in[i]);

    node *root = buildTree(in,pre,0,len - 1);
    
    //inorder(root);
    //printf("\n");

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        int lca = findlca(root,a,b)->data;
        printf("%d\n", lca);
    }
    return 0;
}