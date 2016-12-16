#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define LL long long int
#define ULL unsigned long long int
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

typedef struct edge{
	int u,v,w;
}edge;

#define N 100010

int dsu[N];

int find(int u)
{
	if(dsu[u]==u)
		return u;
	else
		return dsu[u] = find(dsu[u]);
}

void Union(int u,int v)
{
	if(u==v)
		return;
	dsu[u] = v;
}
int cmp(const void *a,const void *b)
{
	return ((edge*)a)->w - ((edge*)b)->w;
}

edge e[N];

int main()
{
	int n,m;
	si(n);si(m);
	int i;
	for(i=0;i<m;i++)
	{
		si(e[i].u);si(e[i].v);si(e[i].w);
	}
	for(i=0;i<=n;i++)
		dsu[i]=i;
	qsort(e,m,sizeof(edge),cmp);
	LL sum=0;
	for(i=0;i<m;i++)
	{
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		int a,b;
		if((a = find(u))!=(b=find(v)))
		{
			Union(a,b);
			sum+=w;
		}
	}
	int flag=1;
	for(i=2;i<=n;i++)
		if(find(i)!=find(i-1))
		{
			flag=0;
			break;
		}
	if(!flag) sum = -1;
	lldout(sum);

	return 0;
}
