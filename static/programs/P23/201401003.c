#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000000
typedef struct list
{
	long long int ver;
	struct list* next;
}list;
list* adj[100009];
long long int a[100010],indegree[100009],len=0;
void shuffle_up(long long int x)
{
	long long int temp;
	while(a[x/2]>a[x])
	{
		temp=a[x/2];
		a[x/2]=a[x];
		a[x]=temp;
		x=x/2;
	}
	return ;
}
void shuffle_down(long long int x)
{
	long long int p,temp;
	while(((2*x)<=len && a[2*x]<a[x]) || (((2*x)+1)<=len && a[(2*x)+1]<a[x]))
	{
		if(a[2*x]<a[(2*x)+1])
		{
			p=2*x;
		}
		else
		{
			p=(2*x)+1;
		}
		temp=a[p];
		a[p]=a[x];
		a[x]=temp;
		x=p;
	}
	return ;
}
void insert(long long int x)
{
	a[++len]=x;
	shuffle_up(len);
	return ;
}
long long int delete_min()
{
	long long int x=a[1];
	a[1]=a[len--];
	shuffle_down(1);
	return x;
}
void insert_list(long long int u,long long int v)
{
	list* p=(list*)malloc(sizeof(list));
	p->ver=v;
	p->next=adj[u];
	adj[u]=p;
	return ;
}
int main()
{
	long long int i,n,m,r,j,u,v,count=0;
	list* t;
	for(i=0;i<100009;i++)
	{
		adj[i]=NULL;
		indegree[i]=0;
	}
	a[0]=-INF;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld",&u,&v);
		insert_list(u-1,v-1);
		indegree[v-1]++;
	}
	for(i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			insert(i);
		}
	}
	while(len>0)
	{
		r=delete_min();
		count++;
		if(count!=n)
			printf("%lld ",r+1);
		else
			printf("%lld\n",r+1);
		t=adj[r];
		while(t)
		{
			indegree[t->ver]--;
			if(indegree[t->ver]==0)
				insert(t->ver);
			t=t->next;
		}
	}
	return 0;
}
