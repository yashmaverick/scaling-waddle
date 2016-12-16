#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ll{
	int v;
	struct ll * next;
}node;
#define MAXN 1000009
node * arr[MAXN];
int dist[MAXN];
int queue[MAXN];

node * insert(int v, node * root)
{
	node * tmp=(node *)malloc(sizeof(node));
	tmp->v=v;
	tmp->next=root;
	return tmp;
}
int bfs(int src, int n){
	memset(dist,-1,sizeof(dist));
	int front=0,rear=0,i,m=-2,mm;
	dist[src]=0;
	queue[rear++]=src;
	while(front!=rear)
	{
		int p=queue[front];
		front++;
		node * tmp=arr[p];
		while(tmp!=NULL)
		{
			if(dist[tmp->v]==-1)
			{
				queue[rear++]=tmp->v;
				dist[tmp->v]=dist[p]+1;
			}
			tmp=tmp->next;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dist[i]>m)
		{
			m=dist[i];
			mm=i;
		}
	}

	return mm;
}
int main(){
	int n,m,u,v,i,temp;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			arr[u]=insert(v,arr[u]);
			arr[v]=insert(u,arr[v]);
		}
		temp=bfs(1,n);	
		temp=bfs(temp,n);
		temp=dist[temp];
		printf("%d\n",temp+1);
		for(i=1;i<=n;i++)
			arr[i]=NULL;
	}
	return 0;
}
