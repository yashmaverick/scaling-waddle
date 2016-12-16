#include<stdio.h>
#include<stdlib.h>
typedef struct str
{
	long long int data;
	struct str *next;
}str;

typedef struct weak
{
	long long int data;
	struct weak *next;
}weak;

str *str_head[100005];
weak *weak_head[100005];

str *insert_str(str* root, long long int n)
{
	str *temp=(str *)malloc(sizeof(str));
	temp->data=n;
	temp->next=root;
	return temp;
}

weak * insert_weak(weak * root,long long int n)
{
	weak *temp=(weak *)malloc(sizeof(weak));
	temp->data=n;
	temp->next=root;
	return temp;
}

long long int nodes_visited=1;
long long int visited[100005];
void dfs(long long int n)
{//nodes_visited++;
	weak *temp=weak_head[n];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			visited[temp->data]=1;
			nodes_visited++;
			dfs(temp->data);
		}
		temp=temp->next;
	}
}
void dfs_str(long long int n)
{//nodes_visited++;
	str *temp=str_head[n];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			visited[temp->data]=1;
			nodes_visited++;
			dfs_str(temp->data);
		}
		temp=temp->next;
	}
}



int main()
{
//	long long int temp[100005];
	long long int n,l,k,i,j,t;
	scanf("%lld",&t);
		for(i=0;i<100005;i++)
		{
			weak_head[i]=NULL;
			str_head[i]=NULL;
			visited[i]=0;
		}
	while(t--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			long long int num;
			scanf("%lld",&num);
			while(num--)
			{
				scanf("%lld",&l);
				str_head[i]=insert_str(str_head[i],l);
				weak_head[l]=insert_weak(weak_head[l],i);
			}
		}
	//	int count=0;
		for(i=1;i<=n;i++)
		{//count=0;
			visited[i]=1;
			nodes_visited=1;
			dfs(i);
			if(nodes_visited==n)
				break;
	/*		for(j=1;j<=n;j++)
			{
				if(visited[j]==1)
					count++;
				visited[j]=0;
			}
			printf("%d\n",count);
			if(count==n)
				break;
			count=0;*/
		}
		long long int src=i;
		nodes_visited=1;
		for(j=0;j<=n;j++)
			visited[j]=0;
		visited[src]=1;
		dfs_str(src);
		printf("%lld\n",nodes_visited);
		for(i=0;i<100005;i++)
		{
			weak_head[i]=NULL;
			str_head[i]=NULL;
			visited[i]=0;
		}
		nodes_visited=1;
	}
	return 0;
}


