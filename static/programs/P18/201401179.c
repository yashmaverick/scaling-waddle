#include<stdio.h>
#include<stdlib.h>

typedef struct LaTree
{
	int n;
	int data;
	struct LaTree *next;
	struct LaTree *neck;	
}LaTree;


void DiameterDfs(int i);
void NEWDFS(int i);

int max;
int deepest;
int visited[10004];
LaTree *head[10004];
LaTree *Leg[10004];
int count,flag=0;
int main()
{
	int Test;
	scanf("%d",&Test);
	while(Test-- >0)
	{
		LaTree *temp;
		int N,M,a,i,val,root=-2,j;
		int node1,node2,check[10004];
		scanf("%d",&N);
		for(i=0;i<=N;i++)
		{	
			head[i]=NULL;
			Leg[i]=NULL;
		}	

		for(node2=1;node2<=N;node2++)
		{
			scanf("%d",&val);
			for(j=0;j<val;j++)
			{
				LaTree *new=(LaTree*)malloc(sizeof(LaTree));
				new->next=NULL;
				scanf("%d",&node1);
				if(head[node1]!=NULL)
				{
					LaTree *temp=NULL;
					new->n=node2;
					new->next=head[node1];
					temp=head[node1];
					head[node1]=new;
					new=temp;
				}	
				else if(head[node1]==NULL)
				{
					head[node1]=(LaTree*)malloc(sizeof(LaTree));
					head[node1]->n=node2;
				}

				if(Leg[node2]!=NULL)
				{
					LaTree *temp=NULL;
					new->data=node1;
					new->neck=Leg[node2];
					temp=Leg[node2];
					Leg[node2]=new;
					new=temp;	
					/*temp=Leg[node2];
					while(temp->neck!=NULL)
					{
						temp=temp->neck;
					}
					temp->neck=(LaTree*)malloc(sizeof(LaTree));
					temp->neck->data=node1;*/
				}
				else if(Leg[node2]==NULL)
				{
					Leg[node2]=(LaTree*)malloc(sizeof(LaTree));
					Leg[node2]->data=node1;
				}
			}
		}
		count=0;
		int k;
		for(i=1;i<=N;i++)
		{
			visited[i]=0;
			check[i]=0;
		}	

		for(i=1;i<=N;i++)
		{	
			flag=0;
			DiameterDfs(i);
			
			if(flag==N-1)
			{
				root=i;
				break;	
			}
			for(k=1;k<=N;k++)
				visited[k]=0;
		}
		for(i=1;i<=N;i++)
			visited[i]=0;

		if(flag==N-1)	
		{	
			NEWDFS(root);
			printf("%d\n",count+1);
		}	
		else
			printf("0\n");

	}	
	return 0;
}
void NEWDFS(int i)
{
	visited[i]=1;
	LaTree* temp;
	temp=Leg[i];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			//printf("visited2[%d]=   %d\n",temp->data,visited[temp->data]);
			count++;
			NEWDFS(temp->data);
		}
		temp=temp->neck;
	}
}

void DiameterDfs(int i) 
{ 
	visited[i]=1;
	LaTree* temp;
	temp=head[i];
	while(temp!=NULL)
	{

		if(visited[temp->n]==0)
		{
			flag++;
			DiameterDfs(temp->n);
		}
		temp=temp->next;
	}
}
/*for(j=1;j<=N;j++)
			{	
				if(visited[j]==0)
				{
					k=j;
					flag=1;
					break;
				}	
				else
				{
					visited[j]=0;
					check[i]++;
					root=i;
				}

				
			}*/