#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
typedef struct adj 
{
	long long int weight;
	long long int des;
	struct adj *next;
}adj;
adj *B[100001];
void adjacency(long long int src,long long int des,long long int value)
{
	adj *new=(adj*)malloc(sizeof(adj));
	new->weight=value;
	new->des=des;
	new->next=B[src];
	B[src]=new;
}
typedef struct node{
	long long int value;
	long long int index;
}node;
node A[100001];
long long int k=1,n;
long long int vis[100001]={0},dist[100001]={INT_MAX},ans=0,c=0;
void shuffleup(long long int p)
{
	node temp;
	if(p>1)
	{
		if(A[p].value>=A[p/2].value)
			return ;
		else
		{
			temp.value=A[p].value;
			temp.index=A[p].index;

			A[p].value=A[p/2].value;
			A[p].index=A[p/2].index;

			A[p/2].value=temp.value;
			A[p/2].index=temp.index;
			p=p/2;

			shuffleup(p);
		}
	}
}
void insert(long long int m,long long int v)//places elements in array with order
{
	if(k==1)
	{
		A[k].value=m;
		A[k].index=v;
		k=k+1;
	}
	else
	{
		A[k].value=m;
		A[k].index=v;
		shuffleup(k);
		k=k+1;
	}
}
node deletemin()//deletes a number and arranges
{
	long long int i=1,j;
	node ret;
	ret.value=A[1].value;
	ret.index=A[1].index;
	A[1].value=A[k-1].value;
	A[1].index=A[k-1].index;
	k--;
	while(2*i<=k-1)
	{
		if(2*i==k)
			j=2*i;
		if(A[2*i+1].value>A[2*i].value)
			j=2*i;
		else
			j=2*i+1;
		if(A[i].value>A[j].value)
		{
			node t;
			t.value=A[i].value;
			t.index=A[i].index;

			A[i].value=A[j].value;
			A[i].index=A[j].index;

			A[j].value=t.value;
			A[j].index=t.index;

			i=j;
		}
		else
			break;
	}
	return ret;
}
void dijstra(long long int u)
{
	long long int i;
	dist[u]=0;
	insert(0,u);
	//	for(i=1;i<=k-1;i++)
	//		printf("A[%lld]=%lld ",i,A[i].index);
	//	printf("\n");
	while(k!=1)
	{
		u=deletemin().index;
		if(vis[u]!=1)
		{
			ans+=dist[u];
			c++;
		}
		//printf("c=%lld\n",c);
		//printf("u=%lld\n",u);
	//	printf("k=%lld\n",k);
		adj *temp=B[u];
		while(temp!=NULL)
		{
			if(vis[temp->des]!=1)
			{
				if(((temp->weight))<dist[temp->des])
				{
					dist[temp->des]=(temp->weight);
					insert(dist[temp->des],temp->des);
				}
			}
			temp=temp->next;
		}
//		for(i=1;i<=k-1;i++)
//			printf("A[%lld]=%lld ",i,A[i].index);
//		printf("\n");
		vis[u]=1;
	}
//	printf("kk=%d\n",k);
	return ;
}
int main()
{
	long long int n,m,i,u,v,w,src,des;
	adj *temp;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		B[i]=NULL;
		dist[i]=INT_MAX;
		vis[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		adjacency(u,v,w);
		adjacency(v,u,w);
	}
	//	scanf("%lld%lld",&src,&des);
	/*for(i=1;i<=n;i++)
	  {
	  printf("i: %lld",i);
	  temp=B[i];
	  while(temp!=NULL)
	  {
	  printf("weight:");
	  printf("%lld ",temp->weight);
	  printf("des:");
	  printf("%lld ",temp->des);
	  temp=temp->next;
	  }
	  printf("\n");
	  }*/
	dijstra(1);
	//if(dist[des]==INT_MAX)
	//	printf("NO\n");
	//else
	//	printf("%lld\n",dist[des]);
	if(c!=n)
		printf("-1\n");
	else
	printf("%lld\n",ans);
	return 0;
}
