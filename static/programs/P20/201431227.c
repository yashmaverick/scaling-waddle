#include<stdio.h>
#include<stdlib.h>
typedef struct ganja
{
	struct ganja *next;
	int data;
}ganja;
int maxlevel=-1;
int maxindex;
ganja* graph[1000005];
void addganja(int i,int j)
{
	ganja *temp=malloc(sizeof(ganja));
	temp->data=j;
	temp->next=graph[i];
	graph[i]=temp;
	ganja *temp2;
	temp2=malloc(sizeof(ganja));
	temp2->data=i;
	temp2->next=graph[j];
	graph[j]=temp2;
}
int visited[1000005];
int level[1000005];
void dfs(int i)
{
	visited[i]=1;
	ganja *temp=graph[i];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
		{

			level[temp->data]=level[i]+1;
			dfs(temp->data);
	
		}
		temp=temp->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		maxlevel=-1;
		scanf("%d",&n);
		int i=0;
		for(i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addganja(x,y);
			
		}
		dfs(1);
		for(i=1;i<=n;i++)
		{
			if(maxlevel<level[i])
			{
				maxlevel=level[i];
				maxindex=i;

			}
			visited[i]=0;
			level[i]=0;
		}
	//	level[maxindex]=0;
		dfs(maxindex);
		maxlevel=-1;
		for(i=1;i<=n;i++)
		{
			if(maxlevel<level[i])
				maxlevel=level[i];
		}
		printf("%d\n",maxlevel+1);
		for(i=1;i<=n;i++)
		{
			level[i]=0;
			visited[i]=0;

			graph[i]=NULL;
		}

	}
	return 0;
}
	
		


	

	



			


