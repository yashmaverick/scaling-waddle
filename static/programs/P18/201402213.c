#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int a;
	struct node *next;
}node;
node *win[1010]={NULL};
node *loose[1010]={NULL};
int visited[1010];
int count;
void dfs(int i)
{
	visited[i]=1;
	node *temp=win[i];
	while(temp!=NULL)
	{
		if(visited[temp->a]==0)
			dfs(temp->a);
		temp=temp->next;
	}
}
void revdfs(int i)
{
	visited[i]=1;
	node *temp=loose[i];
	while(temp!=NULL)
	{
		if(visited[temp->a]==0)
			revdfs(temp->a);
		temp=temp->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j;
		for(i=1;i<1010;i++)
			win[i]=loose[i]=NULL;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			int m;
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				int x;
				scanf("%d",&x);
				node *newptr=(node *)malloc(sizeof(node));
				newptr->a=x;
				newptr->next=loose[i];
				loose[i]=newptr;
				newptr=(node *)malloc(sizeof(node));
				newptr->a=i;
				newptr->next=win[x];
				win[x]=newptr;
			}
		}
		int winner=-1;
		for(i=1;i<=n;i++)
		{
			int state=0;
			for(j=1;j<=n;j++)
				visited[j]=0;
			dfs(i);
			for(j=1;j<=n;j++)
				if(visited[j]==0)
					state=1;
			if(state==0)
			{
				winner=i;
				break;
			}
		}
		if(winner==-1)
		{
			printf("0\n");
			continue;
		}
		count=0;
		for(i=1;i<=n;i++)
			visited[i]=0;
		revdfs(winner);
		for(i=1;i<=n;i++)
			if(visited[i]==1)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
