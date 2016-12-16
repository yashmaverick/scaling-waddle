#include<stdio.h>
#include<stdlib.h>
struct node{
	long long int data;
	struct node *next;
};
typedef struct node noddy;
long long int maxd=0,maxn,visit[1000007];
noddy *a[1000007];
noddy* create(int e)
{
	noddy* p=(noddy*)malloc(sizeof(noddy));
	p->data=e;
	p->next=NULL;
	return p;
}

void insert(long long int u,long long int v)
{
	noddy *q;
	q=a[u]->next;
	a[u]->next=create(v);
	a[u]->next->next=q;
	return;
}

long long int count=0;
void dfs(long long int e,long long int dep)
{

	long long int i;
	noddy *w;

	if(visit[e]==1)
		return;
	if(dep>maxd)
	{
		maxd=dep;
		maxn=a[e]->data;
	}
	//	printf("%d%%%d\n",maxn,maxd);	

	visit[e]=1;
	w=a[e];
	if(w!=NULL)
		w=w->next;

//	count=count+1;
	while(w!=NULL)
	{
		if(visit[w->data]==0)
			dfs(w->data,dep+1);
		w=w->next;
	}
	return;
}

int main()
{
	long long int t,i,n,p,u,v;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{maxd=1;
		scanf("%lld",&n);
		for(p=1;p<=n;p++)
		{
			visit[p]=0;
		}
		for(p=1;p<=n;p++)
		{
			a[p]=create(p);
		}
		for(p=1;p<=n-1;p++)
		{
			scanf("%lld%lld",&u,&v);
			insert(u,v);
			insert(v,u);
		}
		dfs(u,1);
		for(p=1;p<=n;p++)
		{
			visit[p]=0;
		}
//		printf("%d=%d",maxn,maxd);	
		dfs(maxn,1);

		printf("%lld\n",maxd);

	}
	return 0;
}


