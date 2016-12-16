#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#define set(ch,a) memset(ch,a,sizeof(ch))
#define ml(a) (a*)malloc(sizeof(a))
typedef struct tree{
	int h,v,n;
	struct tree* r;struct tree* l;
}tree;
void preprint(tree* root)
{       if(root==NULL)
	return;
	printf("%d %d %d\n",root->v,root->h,root->n);
	preprint(root->l);
	preprint(root->r);
}

int max(int a,int b)
{	return a>b?a:b;}
int height(tree* hd)
{       if(hd==NULL)
	return 0;
	if(hd->r==NULL && hd->l==NULL)
		hd->h=0;
	else if(hd->r==NULL)
		hd->h=hd->l->h+1;
	else if(hd->l==NULL)
		hd->h=hd->r->h+1;
	else
		hd->h=max(hd->r->h,hd->l->h) +1;
	return hd->h;
}
int num(tree* hd)
{       if(hd==NULL)
	return 0;
	if(hd->r==NULL && hd->l==NULL)
		hd->n=1;
	else if(hd->r==NULL)
		hd->n=hd->l->n+1;
	else if(hd->l==NULL)
		hd->n=hd->r->n+1;
	else
		hd->n=hd->r->n+hd->l->n +1;
	return hd->n;
}

tree* l2rrot(tree* root)
{       if(root==NULL || root->l==NULL)return root;
	tree* t=root->l->r;tree* ret=root->l;
	root->l->r=root;
	root->l=t;
	root->h=height(root);root->n=num(root);
	ret->h=height(ret);ret->n=num(ret);
	return ret;
}
tree* r2lrot(tree* root)
{if(root==NULL || root->r==NULL)return root;
	tree* t=root->r->l;tree* ret=root->r;
	root->r->l=root;
	root->r=t;
	root->h=height(root);root->n=num(root);
	ret->h=height(ret);ret->n=num(ret);
	return ret;
}

tree* rrot(tree* hd)
{	if(hd->r==NULL)return hd;
	tree* tmp=hd;
	//tmp->v=hd->v;tmp->l=hd->l;
	hd->r->l=tmp;
	hd->r=hd->r->l;
	height(hd->r);height(hd);
	return hd->r;
}
tree* lrot(tree* hd)
{ if(hd->l==NULL)return hd;
	tree* tmp=hd;
	//tmp->v=hd->v;tmp->r=hd->r;
	hd->l->r=tmp;
	hd->l=hd->l->r;
	height(hd->r);height(hd);
	return hd->l;
}
tree* insert(tree* hd,int a)
{	if(hd==NULL)
	{	hd=ml(tree);
		hd->v=a;hd->h=0;hd->l=hd->r=NULL;hd->n=1;
		return hd;}
	if(hd->v<a)
		hd->r=insert(hd->r,a);
	else hd->l=insert(hd->l,a);
	hd->h=height(hd);hd->n=num(hd);
	if(hd->l==NULL)
	{	if(hd->r->h)
		{	if(hd->r->r==NULL)
			hd->r=l2rrot(hd->r);
			hd=r2lrot(hd);}
	} 
	else if(hd->r==NULL)
	{	if(hd->l->h)
		{if(hd->l->l==NULL)
			hd->l=r2lrot(hd->l);
		}hd=l2rrot(hd);
	}
	else if(hd->l->h<hd->r->h-1)
	{	if(hd->r->r==NULL || (hd->r->l!=NULL &&hd->r->r->h<hd->r->l->h))
		hd->r=l2rrot(hd->r);
		hd=r2lrot(hd);
	}
	else if( hd->r->h<hd->l->h-1)
	{	if(hd->l->l==NULL || (hd->l->r!=NULL && hd->l->l->h<hd->l->r->h))
		hd->l=r2lrot(hd->l);
		hd=l2rrot(hd);
	}
	return hd;
}
void CH(tree* hd,int x)
{	if(hd==NULL)printf("NO\n");
	else if(hd->v==x)
	printf("YES\n");
	else if(hd->v<x)
		CH(hd->r,x);
	else
		CH(hd->l,x);
}
int H(tree* hd,int x)
{	if(hd==NULL)return -1;
	if(x>hd->n)return -1;
	if(hd->l==NULL && x==1)return hd->v;
	if(hd->l==NULL)return H(hd->r,x-1);
	else if(hd->l->n>=x)return H(hd->l,x);
	else if(hd->l->n==x-1)return hd->v;
	else return H(hd->r,x-hd->l->n-1);
}
int RB(tree* hd, int x)
{	if(hd==NULL)return 0;
	else if(hd->l==NULL)
	{if(hd->v==x)return 0; 
		else if(hd->v>x)return 0;
		else return RB(hd->r,x)+1;
	}
	else if(hd->v<x) return RB(hd->r,x)+hd->l->n +1;
	else return RB(hd->l,x);
}
int main()
{	tree* head=NULL;//=ml(tree);head->l=NULL;head->r=NULL;head->v=1;
	int i,q,n,j,m,k=0;char ar[100];
	while(k==0)
	{	scanf("%s",ar);
		switch(ar[0])
		{case 'Q':k=1;break;
			case 'S': sc(i);head=insert(head,i);break;
			case 'C': sc(i);CH(head,i);break;
			case 'H':sc(i);j=H(head,i);
				 if(j>-1)printf("%d\n",j);
				 else printf("NONE\n");
				 break;
			case 'R':sc(i);printf("%d\n",RB(head,i));
		}
	}
	return 0;
}


