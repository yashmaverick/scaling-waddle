#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#include<limits.h>
#define set(ch,a) memset(ch,a,sizeof(ch))
#define ml(a) (a*)malloc(sizeof(a))
long long seg[1000001],sz,vis[100005];
struct pair{
	        int nu,dis;
		        struct pair* n;
};
typedef struct pair pair;
int delm(int b,int e,int n)
{	if(b==e)
	{seg[0]=seg[n];seg[n]=LLONG_MAX;return b;}
	int a;
	if(seg[2*n]==seg[n])
		a=delm(b,(b+e)/2,2*n);
	else
		a=delm((b+e)/2+1,e,2*n+1);
	seg[n]=seg[2*n]>seg[2*n+1]?seg[2*n+1]:seg[2*n];
	return a;
}
void update(int b, int e, int n, int i, long long w)
{	if(b==e)
	{seg[n]=w<seg[n]?w:seg[n];return;}
	if(i<=(b+e)/2)
		update(b,(b+e)/2,2*n,i,w);
	else
		update((b+e)/2+1,e,2*n+1,i,w);
	seg[n]=seg[2*n]>seg[2*n+1]?seg[2*n+1]:seg[2*n];
}

int main()
{	//DRT(){
	set(seg,127);set(vis,0);
	pair* adj[100001];
	int n,m,i,e,Aq,Bq,w,in;
	sc(n);sc(m);
	f(i,0,n+2)
	{   vis[i]=0;adj[i]=NULL;}
	f(i,0,m)
	{   sc(in);sc(e);sc(w);
		pair* p=malloc(sizeof(pair));
		p->nu=e;p->dis=w;
		p->n=adj[in];
		adj[in]=p;
	}
	scanf("%d%d",&Aq,&Bq);
	vis[Aq]=1;
	pair* v=adj[Aq];
	long long  pop=0,MAX=LLONG_MAX/4;
//	printf("hi\n");
	while(!vis[Bq] && pop<MAX)
	{	while(v!=NULL)
		{if(!vis[v->nu])
				update(1,n,1,v->nu,pop+v->dis);
//	printf("hi\n");
		v=v->n;
		}
		int nx=delm(1,n,1);
		if(vis[nx])v=NULL;
		else {v=adj[nx];pop=seg[0];vis[nx]=1;}
	}
	if(vis[Bq] && pop<MAX)
		printf("%lld\n",pop);
	        else
			                printf("NO\n");
		        return 0;
}

