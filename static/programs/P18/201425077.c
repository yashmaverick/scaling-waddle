#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	struct node *next;
	int data;

}node;


void dfs(int visited[],node *a[],int index)
{
	visited[index]=1;

	node *temp=a[index];

	while(temp)
	{
		if(visited[temp->data] == 0)
			dfs(visited,a,temp->data);

		temp=temp->next;
	}

}


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,i,j,visited[100000];
		scanf("%d",&n);

		struct node *a[100000],*b[100000];

		for(i=1;i<=100000;i++)
		{
			a[i]=NULL;
			b[i]=NULL;
		}	

		for(i=1;i<=n;i++)
		{
			int m;
			scanf("%d",&m);

			for(j=1;j<=m;j++)
			{
				int tempdata;
				scanf("%d",&tempdata);

				node *temp=NULL;                           //beat
				temp=(node *)malloc(sizeof(node));

				temp->next=a[tempdata];
				a[tempdata]=temp;
				temp->data=i;

				
				temp=NULL;                                 // beaten
				temp=(node *)malloc(sizeof(node));

				temp->next=b[i];
				b[i]=temp;
				temp->data=tempdata;



			}

		}

		int count=0; int firstwinner;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=100000;j++)
				visited[j]=0;

			dfs(visited,a,i);

			int flag=0;

			for(j=1;j<=n;j++)
				if(visited[j]==0)
				{
					flag=1;
					break;
				}

			if (flag==0)
			{
				firstwinner=i;
				break;
			}
				
		}

		for(i=1;i<=n;i++)

			visited[i]=0;

		dfs(visited,b,firstwinner);

		count=0;
		for(i=1;i<=n;i++)
			if(visited[i]==1)
				count++;



		printf("%d\n",count);

	}


	return 0;
}
