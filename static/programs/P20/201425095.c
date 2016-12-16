#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int vertex;
	struct node *next;
};

struct node *array[1000000];
int visitedarray[1000000];
void adjlist(int u, int v)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->vertex = u;
	temp->next = NULL;
	if(array[v]==NULL)
		array[v]=temp;
	else
	{
		temp->next= array[v];
		array[v] = temp;
	}
}
int max=0, ver=0;
void longestpath(int depth, int u)
{
	visitedarray[u]=1;
	if(depth>=max)
	{
		max=depth;
		ver=u;
	}
	struct node *x;
	x = array[u];
	while (x!=NULL)
	{
		if (visitedarray[x->vertex]==0)
			longestpath(depth+1, x->vertex);
		x=x->next;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while ( t-- )
	{


		int n;
		scanf("%d", &n);
		int i;
		memset(array,0,n*sizeof(struct node));
		for(i=1;i<=(n-1);i++)
		{
			int u;
		       	int v;
			scanf("%d %d", &u, &v);
			adjlist(u,v);
			adjlist(v,u);
		}

		/*for(i=1;i<=n;i++)
		{
			struct node *temp=array[i];
			
			while(temp!=NULL)
			{
				printf("%d\n",temp->vertex);
				temp=temp->next;
			}
		putchar('\n');
		}*/

		max=0; ver=0;
		
		for(i=1; i<=n; i++)
			visitedarray[i]=0;

		longestpath(1,1);
		max=0;


		for(i=1; i<=n; i++)
			visitedarray[i]=0;

		longestpath(1,ver);
		

		printf("%d\n", max);	
		//struct node temp;

	}
}
