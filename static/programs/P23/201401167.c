#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#define set(ch,a) memset(ch,a,sizeof(ch))
#include<limits.h>
int st[500005],t,n,ch[100005],vis[100005];
struct node{
	int nu;
	struct node* n;};
typedef struct node node;
node* adj[100005];
typedef struct heap{
	long long n,w;
}heap;
int sz1,sz2,par[100005];
void insert(int a,int sz)
{	st[sz]=a;//printf("%d %d\n",sz,a);//st[sz]=b;
	while(sz>1 && st[sz/2]>st[sz])
	{	int t=st[sz];
		st[sz]=st[sz/2];
		st[sz/2]=t;
		sz/=2;
	}
}
int pop(int fl)
{	if(sz1==0)return INT_MAX;	
	int t;int p;
		t=st[1];p=1;
		st[1]=st[sz1];
		while((st[p]>st[2*p] || st[p]>st[2*p+1]) && 2*p<sz1)
		{	if(st[2*p]<st[2*p+1])
			{	int a=st[p];
				st[p]=st[2*p];
				st[2*p]=a;
				p*=2;}
			else {int a=st[p];
				st[p]=st[2*p+1];
				st[2*p+1]=a;
			p=2*p+1;}
		}
		if(st[p]>st[2*p]&&2*p==sz1)
		{       int a=st[p];
			st[p]=st[2*p];
			st[2*p]=a;
		}
		sz1--;
	return t;
}

int dfs(int i)
{	vis[i]=1;node* it=adj[i];
	while(it!=NULL)
	{	if(--par[it->nu]<=0)
		insert(it->nu,++sz1);
		it=it->n;
	}
	int a=pop(1);
	if(a!=INT_MAX && !vis[a])
	{	if(sz2<n-1)
		printf("%d ",a);
		else
			printf("%d",a);
			sz2++;dfs(a);}
}

int main()
{	int m,i,in,e;
	set(ch,0);set(vis,0);t=0;sz1=0;sz2=0;
	sc(n);sc(m);set(par,0);
	f(i,0,m)
	{ 	sc(in);sc(e);//sc(w);
		node* p=malloc(sizeof(node));
		p->nu=e;ch[p->nu]=1;p->n=adj[in];
		adj[in]=p;
		par[e]++;
	}
	f(i,1,n+1)
		if(!ch[i])
			insert(i,++sz1);
	int a=pop(1);
	while(a!=INT_MAX && !vis[a])
	{if(sz2<n-1)printf("%d ",a);
		else printf("%d",a);
		sz2++;dfs(a);a=pop(1);}
	printf("\n");
return 0;
}
