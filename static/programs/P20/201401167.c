#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#include<limits.h>
#define set(ch,a) memset(ch,a,sizeof(ch))
#define ml(a) (a*)malloc(sizeof(a))
typedef struct node{
	int v;
	struct node* n;}
	node;
node* adj[1000000];int v[1000000],md=0;int mn;
void dfs(int i,int d)
{//	if(i>50000)
	v[i]=1;
	if(d>md)
	{	md=d;	mn=i;
	}
	node* it=adj[i];
	while(it!=NULL)
	{	if(v[it->v]==0)
			dfs(it->v,d+1);
		it=it->n;
	}
}
int main()
{	DRT(){
	int n,i,j,m;int vis[100];md=0;
	set(vis,0);set(v,0);
	sc(n);f(i,0,1000000)adj[i]=NULL;
	f(i,0,n-1)
	{	sc(j);sc(m);
		//j=i;m=i+1;
		node* p=ml(node);node* q=ml(node);
		p->v=m;q->v=j;
		p->n=adj[j];q->n=adj[m];
		adj[j]=p;adj[m]=q;
//		vis[j]++;vis[m]++;
//
	}
	dfs(1,0);set(v,0);
	dfs(mn,0);
	printf("%d\n",md+1);
}
	return 0;
}

