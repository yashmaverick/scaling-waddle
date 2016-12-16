#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct graph
{
	int value;
	struct graph *next;
};

int visited[1000009];
struct graph * arr[1000009];
int mani[1000009];

struct graph * insert(int v,struct graph *root)
{
	struct graph * temp=(struct graph *)malloc(sizeof(struct graph));
	temp->value=v;
	temp->next=root;
	return temp;
}

int queue[1000009],top=0,start=0;

int bfs(int u)
{
	int temp;
	queue[top]=u;
	visited[u]=1;
	top++;
	struct graph* tmp;
	while(top!=start)
	{
		temp=queue[start];
		//cout<<temp;
		int val=mani[queue[start]];
		start++;
		tmp=arr[temp];

		while(tmp!=NULL)
		{
			if(visited[tmp->value]==0)
			{
				queue[top]=tmp->value;

				mani[queue[top]]=val+1;

				top++;
				visited[tmp->value]=1;
			}
			tmp=tmp->next;
		}
	}
	return temp;
}

int bfs2(int u)
{
	int temp;
	queue[top]=u;
	visited[u]=1;
	top++;
	struct graph* tmp;
	while(top!=start)
	{
		temp=queue[start];

		start++;
		tmp=arr[temp];

		while(tmp!=NULL)
		{
			if(visited[tmp->value]==0)
			{
				queue[top]=tmp->value;
				top++;
				visited[tmp->value]=1;
			}
			tmp=tmp->next;
		}
	}
	return temp;
}


int main()
{
	int n,i,j,x,y,u,t;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&x,&y);
			arr[x]=insert(y,arr[x]);
			arr[y]=insert(x,arr[y]);
		}

		int temp;
		temp=bfs2(1);

		memset(visited,0,1000009);
		memset(queue,0,1000009);
		start=top=0;

		temp=bfs(temp);
		printf("%d\n",mani[temp]+1);
		
		memset(visited,0,1000009);
		memset(queue,0,1000009);
		memset(mani,0,1000009);
		start=top=0;
		
		for(i=1;i<=n;i++)
		{
			while(arr[i]->next!=NULL)
			{
				arr[i]->next=arr[i]->next->next;
				arr[i]->next=NULL;
			}
			arr[i]=NULL;
		}

		t--;
	}
	return 0;
}
