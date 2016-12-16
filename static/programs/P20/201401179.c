#include<stdio.h>
#include<stdlib.h>

typedef struct LaTree
{
	int n;
	struct LaTree *next;
}LaTree;

int DiameterDfs(int i,int depth);

int max;
int deepest;
int visited[1000002];
LaTree *head[1000002];

int main()
{
	int Test;
	scanf("%d",&Test);
	while(Test-- >0)
	{
		LaTree *temp;
		int N,M,a,i,val,root;
		int node1,node2;
		scanf("%d",&N);
		if(N==1)
		{
			scanf("%d",&node1);
			printf("1\n");
		}
		else if(N==0)
			printf("0\n");	
		else if(N==2)
		{
			scanf("%d%d",&node1,&node2);
			printf("2\n");
		}
		else
		{
			for(i=0;i<=N;i++)
				head[i]=NULL;

			
			for(i=1;i<N;i++)
			{
				scanf("%d%d",&node1,&node2);
				if(i==1)
					root=node1;

				if(head[node1]!=NULL)
				{
					temp=head[node1];
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=(LaTree*)malloc(sizeof(LaTree));
					temp->next->n=node2;
				}
				else if(head[node1]==NULL)
				{
					head[node1]=(LaTree*)malloc(sizeof(LaTree));
					head[node1]->n=node2;
				}

				if(head[node2]!=NULL)
				{
					temp=head[node2];
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=(LaTree*)malloc(sizeof(LaTree));
					temp->next->n=node1;
				}
				else if(head[node2]==NULL)
				{
					head[node2]=(LaTree*)malloc(sizeof(LaTree));
					head[node2]->n=node1;
				}
			}
			max=0;
			for(i=0;i<=N;i++)
				visited[i]=0;

			int value=DiameterDfs(root,0);
			for(i=0;i<=N;i++)
				visited[i]=0;

			max=0;
			value=deepest;
			deepest=0;	
			value=DiameterDfs(value,0);
			printf("%d\n",max+1);
		}
	}	
	return 0;
}

int DiameterDfs(int i,int depth) 
{ 
	int num;
	visited[i]=1;
	LaTree* temp;
	temp=head[i];
	while(temp!=NULL)
	{
		if(visited[temp->n]==0)
		{
			num=DiameterDfs(temp->n,depth+1);
			if(num>max)
			{
				max=num;
				deepest=temp->n;
//				printf("max=%d\n",max);				
			}

		}
		temp=temp->next;
	}
	return depth;
}
