#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    int ht,lc,rc;
    struct node* l;
    struct node* r;
};
typedef struct node node;
typedef node* link;
int fl=0,rbans=0;

link insert(link ,int);
void preorder(link);
int height(link);
void updh(link);
void updlc(link);
void updrc(link);
void search(link,int);
void rot(link,int);
link check(link,int);
link rrot(link);
link lrot(link);

link insert(link root,int val)
{
    if(root==NULL)
    {
	root=(link) malloc(sizeof(node));
	root->l=NULL;
	root->r=NULL;
	root->lc=0;
	root->rc=0;
	root->val=val;
    }
    else
    {
	if(val < root->val)
	{
	    root->l=insert(root->l,val);
	}
	else
	{
	    root->r=insert(root->r,val);
	}
    }
    updh(root);
    updlc(root);
    updrc(root);

    root=check(root,val);
    //  printf("after check\n");
    //  preorder(root);
    return root;
}

void preorder(link root)
{
    if(root==NULL)
	return;
    printf("   %d, ht=%d,lc=%d,rc=%d\n",root->val,root->ht,root->lc,root->rc);
    preorder(root->l);
    preorder(root->r);
    return;
}

int height(link root)
{
    if(root==NULL)
	return 0;
    else
	return root->ht;
}

void updlc(link root)
{
    int t;
    if(root->l==NULL)
	t=-1;
    else
	t=(root->l->lc)+(root->l->rc);
    root->lc=t+1;
}
void updrc(link root)
{
    int t;
    if(root->r==NULL)
	t=-1;
    else
	t=root->r->lc+root->r->rc;
    root->rc=t+1;
}

void updh(link root)
{
    root->ht=max(height(root->l),height(root->r))+1;
}

int max(int a,int b)
{
    if(a>=b)
	return a;
    else
	return b;
}

link rrot(link y)
{
    link x=y->l;
    link t2=x->r;
    x->r=y;
    y->l=t2;
    updh(y);updlc(y);updrc(y);
    updh(x);updlc(x);updrc(x);
    return x;
}

link lrot(link x)
{
    link y=x->r;
    link t2=y->l;
    y->l=x;
    x->r=t2;
    updh(x);updlc(x);updrc(x);
    updh(y);updlc(y);updrc(y);
    return y;
}

link check(link root,int val)
{
    //    printf("In check for %d\n",root->val);
    int diff;
    diff=height(root->l)-height(root->r);
    //    printf(" diff=%d\n",diff);
    if(diff>1 && val<root->l->val)
    {
//		printf(" Left left case\n");
	root=rrot(root);
    }
    else if(diff>1 && val>=root->l->val)
    {
//		printf(" Left right case\n");
	root->l=lrot(root->l);
	return rrot(root);
    }
    else if(diff<-1 && val>=root->r->val)
    {
//		printf(" Right right case\n");
	root=lrot(root);
    }
    else if(diff<-1 && val<root->r->val)
    {
//		printf(" Right left case\n");
	root->r=rrot(root->r);
	return lrot(root);
    }
    else
//		printf(" all good\n");
	return root;
}

void search(link root,int val)
{
    if(root==NULL)
	return;
    if(root->val==val)
    {
	fl=1;
	return;
    }
    if(val<root->val)
	search(root->l,val);
    else
	search(root->r,val);
    return;
}

void rot(link root,int x)
{
    if(root==NULL)
	return;
  //      printf("rot @ %d\n",root->val);
    if(root->val==x)
    {
//	printf(" found x, lc=%d\n",root->lc);
	rbans+=root->lc;
    }
    if(x<root->val)
    {
//	printf("x<root->val\n");
	rot(root->l,x);
    }
    if(x>root->val)
    {
//	printf("x>root->val\n ans+=lc+1\n");
	rbans+=root->lc+1;
	rot(root->r,x);
    }
}

void hlt(link root,int x)
{
    if(root==NULL)
	return;
//     printf("hlt @ %d\n",root->val);
//     printf("lc=%d x=%d\n",root->lc,x);
    if(root->lc==x)
    {
//	printf("found\n");
	printf("%d\n",root->val);
    }
    if(root->lc<x)
    {
//	printf("going r i.e.lc<x --> x-1-lc\n");
	hlt(root->r,x-1-root->lc);
    }
    else
    {
//	printf("going l i.e.lc>x\n");
	hlt(root->l,x);
    }
}

int main()
{
    link root=NULL;
    int val,n,x,tot=0;
    char c[50];
    while(1)
    {
//	printf("tree\n");
//	preorder(root);
	scanf("%s",c);
	if(c[0]=='Q')
	    break;
	scanf("%d",&x);
	if(c[0]=='S')
	{
	    tot++;
	    root=insert(root,x);
	}
	if(c[0]=='C')
	{
	    fl=0;
	    search(root,x);
	    if(fl==1)
		printf("YES\n");
	    else
		printf("NO\n");
	}
	if(c[0]=='H')
	{
	    if(tot<x)
		printf("NONE\n");
	    else
	    {
		hlt(root,x-1);
	    }
	}
	if(c[0]=='R')
	{
	    rbans=0;
	    rot(root,x);
	    printf("%d\n",rbans);
	}
    }
   
/*
    ///FOR TESTING
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
    printf("\n");
    scanf("%d",&val);
    root=insert(root,val);
    printf("after insert\n");
    preorder(root);
    }
*/

    return 0;
}
