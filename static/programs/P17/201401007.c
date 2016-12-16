#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}name;
typedef name* ptr;
int globalmanager=0;
int inorder[100000];
int preorder[100000];
ptr mytree(int start,int end)
{
    int i;
    if(start>end)
    {
	return NULL;
    }
    int ntbs=preorder[globalmanager];
    ptr mynode=(ptr)malloc(sizeof(name));
    mynode->value=preorder[globalmanager];
    mynode->left=NULL;
    mynode->right=NULL;
    globalmanager++;
    if(start==end)
    {
	return mynode;
    }
    for(i=start;i<=end;i++)
    {
	if(inorder[i]==ntbs)
	{
	    break;
	}
    }
    mynode->left=mytree(start,i-1);
    mynode->right=mytree(i+1,end);
    return mynode;
}
void printpreorder(ptr root)
{
    ptr tmp=root;
    if(root==NULL)
    {
	return ;
    }
    printf("%d ",tmp->value);
    printpreorder(root->left);
    printpreorder(root->right);
}
typedef struct bogi{
    int nu;
    struct bogi* next;
}link;
typedef link* LL;
LL A[10005];
int marker[10005];
int parenta[10005];
int levela[10005];
LL insert(int n,LL root)
{
    LL tmp=(LL)malloc(sizeof(link));
    tmp->nu=n;
    tmp->next=root;
    return tmp;
}
void print(LL root)
{
    LL tmp=root;
    while(tmp!=NULL)
    {
	printf("%d ",tmp->nu);
	tmp=tmp->next;
    }
    printf("\n");
}
void level(int x,int t)
{
    levela[x]=t;
    int i;
    LL tmp=A[x];
    marker[x]=1;
    t++;
    while(tmp!=NULL)
    {
	if(marker[tmp->nu]==0)
	{
	    parenta[tmp->nu]=x;
	    //	    printf("%d ",tmp->nu);
	    level(tmp->nu,t);
	}
	tmp=tmp->next;
    }
}
int lca(int x,int y)
{
    while(x!=y)
    {
	if(levela[x]>levela[y])
	{
	    x=parenta[x];
	}
	else
	{
	    y=parenta[y];
	}
    }
    return x;
}
void preparelinklist(ptr root)
{
    if(root->left==NULL&&root->right==NULL)
    {
	return ;
    }
    if(root->left!=NULL)
    {
	A[root->value]=insert(root->left->value,A[root->value]);
	A[root->left->value]=insert(root->value,A[root->left->value]);
	preparelinklist(root->left);
    }
    if(root->right!=NULL)
    {
	A[root->value]=insert(root->right->value,A[root->value]);
	A[root->right->value]=insert(root->value,A[root->right->value]);
	preparelinklist(root->right);
    }
}
int main()
{
    int n,i,q,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	scanf("%d",&preorder[i]);
	A[i]=NULL;
    }
    for(i=0;i<n;i++)
    {
	scanf("%d",&inorder[i]);
    }
    ptr root=mytree(0,n-1);
    preparelinklist(root);
/*    for(i=1;i<=n;i++)
    {
	print(A[i]);
    }*/
    level(root->value,1);
    scanf("%d",&q);
    while(q--)
    {
	scanf("%d %d",&x,&y);
	printf("%d\n",lca(x,y));
    }
    return 0;
}
