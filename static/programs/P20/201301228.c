#include<stdio.h>
#include<stdlib.h>
#define max 1000005
typedef struct list
{
	int value;
	struct list *next;
}list;
list *graph[max];
int done[max],result[max],max2[max],max1[max];
void link(list *graph[],int u,int v)
{
	list *current,*new;
	current=graph[u];
	while(current->next!=NULL)
		current=current->next;
	new=(list*)malloc(sizeof(list));
	new->value=v;
	new->next=NULL;
	current->next=new;
}
int min(int x,int y)
{
		return x>y?y:x;
}
void dfs(int v)
{
	int temp;
	list *current;
	done[v]=1;
	current=graph[v]->next;
	while(current!=NULL)
	{
		if(done[current->value]==0)
		{

			dfs(current->value);
			if(result[current->value]>result[v])
				result[v]=result[current->value];
			if(max2[v]<(max1[current->value]+1))
				max2[v]=max1[current->value]+1;
			if(max2[v]>max1[v])
			{
				temp=max2[v];
				max2[v]=max1[v];
				max1[v]=temp;
			}
		}
		current=current->next;
	}
	if((max2[v]+max1[v])>result[v])
		result[v]=max2[v]+max1[v];
}
int main()
{
	int test;
	int count=0,i,u,v,vrtic,edg;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&vrtic);
		edg=vrtic-1;
		for(i=0;i<vrtic;i++)
		{
			done[i]=0;
			max2[i]=0;
			max1[i]=0;
			result[i]=0;
			graph[i]=(list*)malloc(sizeof(list));
			graph[i]->value=i;
			graph[i]->next=NULL;
		}
		for(i=0;i<edg;i++)
		{
			scanf("%d %d",&u,&v);
			u--;
			v--;
			link(graph,u,v);
			link(graph,v,u);	
		}
		for(i=0;i<vrtic;i++)
		{
			if(done[i]==0)
			{
				count++;
				dfs(i);
			}
		}
		printf("%d\n",result[0]+1);
	}
	return 0;
}
