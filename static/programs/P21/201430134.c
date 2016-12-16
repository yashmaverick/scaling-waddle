#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int size,ans;
struct node{
	long long int wt;
	long long int ix;
};
typedef struct node node;
struct ll{
	long long index;
	long long weight;
	struct ll* nxt;
};
typedef struct ll ll;
typedef ll* list;
void insadj(long long int u,long long int v,long long int w,list poin[])
{
	list temp;
	temp=(list)malloc(sizeof(ll));
	temp->index=v;
	temp->weight=w;
	temp->nxt=poin[u];
	poin[u]=temp;
}
void delmin(node a[])
{
	long long int new,min,last,i,tempi;
	min=a[1].wt;
	tempi=a[size].ix;
	last=a[size--].wt;
	for(i=1;size>=2*i;i=new)
	{
		new=2*i;
		if(new!=size && a[new+1].wt<a[new].wt)
		{
			new++;
		}
		if(last>a[new].wt)
		{
			a[i].wt=a[new].wt;
			a[i].ix=a[new].ix;
		}
		else
		{
			break;
		}
	}
	a[i].wt=last;
	a[i].ix=tempi;
}
void insh(long long int weigh,long long int inde,node a[])
{
	long long int i,tempi,tempw;
	size++;
	a[size].wt=weigh;
	a[size].ix=inde;
	for(i=size;i>1 && weigh<a[i/2].wt;i=i/2)
	{
		tempw=a[i].wt;tempi=a[i].ix;
		a[i].wt=a[i/2].wt;a[i].ix=a[i/2].ix;
		a[i/2].wt=tempw;a[i/2].ix=tempi;
	}
	return;
}
void cpu(list poin[],long long int dist[],long long int vis[],node a[],long long int storeix,long long int storewt)
{
	vis[storeix]=1;
	list temp;
	temp=poin[storeix];
	while(temp!=NULL)
	{
		if(vis[temp->index]==0)
		{
			if((storewt+temp->weight) < dist[temp->index])
			{
				dist[temp->index]=storewt+temp->weight;
				insh(dist[temp->index],temp->index,a);
			}
		}
		temp=temp->nxt;
	}
}
int main()
{
	long long int u,v,w,c1,c2;
	long long int n,m,storeix,storewt;
	long long int i,j,k;
	scanf("%lld %lld",&n,&m);
	size=0;ans=0;
	list poin[1000004];
	long long int dist[1000004];
	node a[1000004];
	long long int vis[1000004];
	for(i=0;i<=1000004;i++)
	{
		poin[i]=NULL;
		vis[i]=0;
		dist[i]=1000000004;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		insadj(u,v,w,poin);
	}
	scanf("%lld %lld",&c1,&c2);
	dist[c1]=0;
	insh(0,c1,a);
	while(vis[c2]==0)
	{
		if(size==0)
		{
			ans=1;
			break;
		}
		if(vis[a[1].ix]==0)
		{
			storeix=a[1].ix;
			storewt=a[1].wt;
			delmin(a);
			cpu(poin,dist,vis,a,storeix,storewt);
		}
		else
		{
			delmin(a);
		}
	}
	if(ans==0)
	{
		printf("%lld\n",dist[c2]);
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}

