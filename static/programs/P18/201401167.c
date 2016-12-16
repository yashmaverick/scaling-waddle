#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#define mask1 0xFFF
#define mask2 0x1000
char vis[1002];int bk[1002],h[1002],qu[1002];
int fr,rear,cnt;
struct node{
	int d;
	struct node* n;};
typedef struct node node;node* adj[1001];
int chk(int n)
{	while(n)
		if(vis[n--]==0)
			return 0;
	return 1;
}
void bfs(int a,int d)
{
	rear++;
	h[a]=bk[a]=d;
	node* it=adj[a];
	while(it!=NULL)
	{	if(!vis[it->d])
		{qu[fr]=it->d;vis[it->d]=1;qu[fr]+=(d+1)*mask2;fr++;}
		else if(bk[a]>bk[it->d])
			bk[a]=bk[it->d];
		it=it->n;
	}
	if(rear<=fr)bfs(qu[rear]&mask1,qu[rear]/mask2);
}
int dfs(int a)
{	node* it=adj[a];int t;
	vis[a]=1;
	while(it!=NULL)
	{       if(!vis[it->d])
			dfs(it->d);
			//	bk[a]=t;}
		if(bk[it->d]<bk[a])
			bk[a]=bk[it->d];
		it=it->n;
	}
	return bk[a];
	if(bk[a]==0)cnt++;
}

	
int main()
{	int t;sc(t);while(t--){
	int n,i,j,mn=0xFFFFF,m,o,p=0;
	memset(vis,0,sizeof(vis));memset(qu,0,sizeof(qu));
	sc(n);
	f(i,0,1001)
	{	adj[i]=NULL;h[i]=mask1;bk[i]=mask1;}
	f(i,0,n)
	{	sc(m);if(m<mn){mn=m;p=i+1;}
		f(j,0,m)
		{sc(o);
		node* t=malloc(sizeof(node));
		t->n=adj[o];t->d=i+1;
		adj[o]=t;
		}
	}		
	vis[p]=1;fr=0;rear=-1;cnt=0;
		bfs(p,0);
		memset(vis,0,sizeof(vis));
		dfs(p);
		f(i,0,n){//printf("%d",bk[i+1]);
	if(bk[i+1]==0)
		cnt++;}
		if(chk(n))
			printf("%d\n",cnt);
		else
			printf("0\n");
			      }
	return 0;
}
