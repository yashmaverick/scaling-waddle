#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	long long int data;
	struct node* link;
};

struct node* list[1000005];

void create(long long int e1,long long int e2){
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = e2;
	tmp->link = list[e1];
	list[e1] = tmp;
	return ;
}

long long int vis[1000005]={0},dist[1000005];

void dfs(long long int v, long long int d)
{
	vis[v]=1;
	dist[v]=d;
	//printf("'%lld'-%lld ",dist[v],v);
	struct node* q=list[v];
	while(q!=NULL)
	{
		if(vis[q->data]!=1)
			dfs(q->data,d+1);
		q=q->link;
	}
}

int main()
{
	long long int t,i;
	scanf("%lld",&t);
	while(t--)
	{
		for(i=0;i<1000005;i++)
			list[i]=NULL;
		long long int a,b,max,n,m,maxi=1;
		scanf("%lld",&n);
		if(n==0)
			printf("0\n");
		else
		{
			for(i=0;i<n+1;i++)
		{
			vis[i]=0;
			dist[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&a,&b);
			create(a,b);
			create(b,a);
		}
		dfs(1,0);
		max=dist[1];
		for(i=2;i<n+1;i++)
		{
			if(dist[i]>max)
			{
				max=dist[i];
				maxi=i;
			}
		}
		//printf("%lld\n",n);
		for(i=0;i<n+1;i++)
		{
			vis[i]=0;
			dist[i]=0;
		}
		dfs(maxi,0);
		max=dist[1];
		for(i=2;i<n+1;i++)
		{
			if(dist[i]>max)
				max=dist[i];
		}
		printf("%lld\n",max+1);}
	}
	return 0;
}