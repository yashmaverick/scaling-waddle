#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	struct node *next;
	int data;

}node;

		node *a[1000005];
int visited[1000005];

void dfs(node *a[],int index,int f)
{
	visited[index]=f;

	node *temp=a[index];

	while(temp)
	{
		if(visited[temp->data] == -1)
			dfs(a,temp->data,f+1);

		temp=temp->next;
	}

}


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int i;
		for(i=1;i<=1000005;i++)
			a[i]=NULL;

		int n;
		scanf("%d",&n);
		int m=n;
		n--;
		while(n--)
		{
			int t1,t2;
			scanf("%d %d",&t1,&t2);	
			
			node *temp=(node *)malloc(sizeof(node));
			
			temp->next=a[t1];
			a[t1]=temp;
			temp->data=t2;


			node *temp3=(node *)malloc(sizeof(node));

			temp3->next=a[t2];
			a[t2]=temp3;
			temp3->data=t1;
		
		}
		

/*		for(i=1;i<=m;i++)
		{
			node *temp=a[i];

			while(temp)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}

			printf("\n");
		
		}
*/

		for(i=1;i<1000005;i++)
			visited[i]=-1;

		dfs(a,1,1);

//		for(i=1;i<=m;i++)


		int max=1;


		for(i=1;i<=m;i++)
			if(visited[i]>visited[max])
				max=i;

//		printf("max=%d %d\n",max,visited[max]);


		for(i=1;i<=1000005;i++)
			visited[i]=-1;

		dfs(a,max,1);

//		for(i=1;i<=m;i++)
//			printf("%d ",visited[i]);
//		printf("\n");


		max=1;

		for(i=1;i<=m;i++)
			if(visited[i]>visited[max])
				max=i;

//		printf("max2=%d\n",max);
	

		printf("%d\n",visited[max]);
			
		

	}


	return 0;
}
