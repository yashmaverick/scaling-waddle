#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;
int in[100000],pre[100000];
node *root;
node* mktree(int sti,int eni,int stp,int enp)
{
    if(sti>eni)
    {
	return NULL;
    }
    else
    {
	node *new=malloc(sizeof(node));
	new->val=pre[stp];
	if(stp==enp)
	    new->left=new->right=NULL;
	else if(enp-stp==1)
	{
	    if(in[sti]==pre[stp])
	    {
		new->left=NULL;
		node *nnew=malloc(sizeof(node));
		nnew->val=pre[enp];
		nnew->left=nnew->right=NULL;
		new->right=nnew;
	    }
	    else
	    {
		node *nnew=malloc(sizeof(node));
		nnew->val=pre[enp];
		nnew->left=nnew->right=NULL;
		new->left=nnew;
		new->right=NULL;
	    }
	}
	else
	{
	    int i;
	    for(i=sti;i<=eni;i++)
		if(pre[stp]==in[i])
		    break;
	    int lele=i-sti;
	    int rele=eni-i;
	    new->left=mktree(sti,i-1,stp+1,stp+lele);
	    new->right=mktree(i+1,eni,stp+lele+1,enp);
	}
	return new;
    }
}
node *lca(node *cur,int x,int y)
{
    if(cur->val==x || cur->val==y)
	return cur;
    node *l,*r;
    if(cur->left==NULL)
	l=NULL;
    else
	l=lca(cur->left,x,y);
    if(cur->right==NULL)
	r=NULL;
    else
	r=lca(cur->right,x,y);
    if(l==NULL && r==NULL)
	return NULL;
    if(l==NULL)
	return r;
    if(r==NULL)
	return l;
    if(l!=r)
	return cur;
}
int main()
{
    int n,i;
    int x,y,tl;
    int sti,eni,stp,enp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
	scanf("%d",&in[i]);
    root=mktree(0,n-1,0,n-1);
    scanf("%d",&tl);
    while(tl--)
    {
    scanf("%d %d",&x,&y);
    node *lc=lca(root,x,y);
    printf("%d\n",lc->val);
    }
    return 0;
}
