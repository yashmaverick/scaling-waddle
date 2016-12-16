#include<stdio.h>
#include<stdlib.h>
int N;
int count;
int cnt;
int visited[1010];
typedef struct adjnode
{
	struct adjnode* next;
	int value;
}adjnode;
//struct adjnode *array[1010],*array2[1010];
adjnode* newnode(int v)
{
	adjnode* newn;
	newn = (struct adjnode*)malloc(sizeof(struct adjnode));
	newn->value = v;
	newn->next = NULL;
	return newn;
}
void addedge( int src, int dest,adjnode **array)
{
	adjnode* node;
	node = newnode(dest);
	node->next = array[src];
	array[src] = node;
}
void addedge2( int src, int dest,adjnode **array2)
{ 
	adjnode* node;
	node = newnode(dest);
	node->next = array2[src];
	array2[src] = node;
}
void dfs( int v,adjnode **array)
{
	int i;
	visited[v] = 1;
	adjnode *pt;
	pt = array[v];
	while(pt)
	{
		if(visited[pt->value] == 0)
			dfs(pt->value,array);
		pt = pt->next;
	}
}
void dfs2( int v,adjnode **array2)
{
	int i;
	visited[v] = 1;
	adjnode *pt;
	pt = array2[v];
	//	printf("w:%d\n",v);
	while(pt)
	{
		if(visited[pt->value] == 0)
			dfs2(pt->value,array2);
		pt = pt->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i;
		adjnode *array[1010],*array2[1010];
		for(i=0;i<=1010;i++)
			visited[i]=0;
		cnt=0;
		int M,a,n;
		int x;
		scanf("%d",&N);
		for(n=0;n<1010;n++)
		{
			array2[n]=NULL;
			array[n]=NULL;
		}
		for(n=1;n<=N;n++)
		{
			scanf("%d",&M);
			for(i=0;i<M;i++)
			{
				scanf("%d",&a);
				addedge(a,n,array);
				addedge2(n,a,array2);
			}
		}


		int flag=0;
		for(n=1;n<=N;n++)
		{
			count=0;
			for(i=0;i<=N;i++)
				visited[i] = 0;
			dfs(n,array);
			for(i=1;i<=N;i++)
			{
				if(visited[i]==1)
					count++;
			}
			//			printf("count:%d\n",count);
			if(count == N)
			{
				x = n;
//				flag=1;
				break;
			}
			//			printf("count = %d\n",count);
		}
//		if(flag==1)
//		{
			flag=0;
			//		printf("x: %d\n",x);
			for(i=0;i<=N;i++)
				visited[i]=0;
			dfs2(x,array2);
			for(i=1;i<=N;i++)
			{
				if(visited[i] == 1)
				{
					//					printf("wd:%d\n",i);
					cnt++;
				}
			}
			printf("%d\n",cnt);
//		}
//		else
//			printf("-1\n");
	}
	return 0;
}
