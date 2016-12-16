#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *A[1005],*B[1005];
int visited[1005],check_list[1005],winner,win,count,n;
void dfs(int vi)
{
	visited[vi]=1;
	check_list[vi]=1;
	node *temp;
	temp=A[vi];
//	printf("dfs\n");
//	printf("%d\n",temp->data);
	while(temp!=NULL)
	{
//		printf("while\n");
		if(visited[temp->data]==0)
		{
			count++;
			dfs(temp->data);
		}
		temp=temp->next;
	}
}

void reverse_dfs(int vi)
{
	visited[vi]=1;
//	check_list[vi]=1;
	node *temp;
	count++;
	temp=B[vi];
//	printf("revdfs\n");
//	printf("%d\n",temp->data);
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
		//	count++;
			reverse_dfs(temp->data);
		}
		temp=temp->next;
	}

}

void adj_list(int vi, int vj)
{	
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=vj;
	temp->next=NULL;
	if(temp==NULL)
		A[vi]=temp;
	else
	{
		temp->next=A[vi];
		A[vi]=temp;
	}

}

void adj_revlist(int vi,int vj)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=vj;
	temp->next=NULL;
	if(temp==NULL)
		B[vi]=temp;
	else
	{
		temp->next=B[vi];
		B[vi]=temp;
	}

}

int main()
{
	int test,i,j,num1,num2,k;
	node *temp1;
	scanf("%d",&test);
	while(test--)
	{
		for(i=1;i<1005;i++)
		{
			visited[i]=0;
			check_list[i]=0;
			A[i]=NULL;
			B[i]=NULL;
		}
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num1);
			for(j=0;j<num1;j++)
			{
				scanf("%d",&num2);
				adj_list(num2,i);
				adj_revlist(i,num2);
			}
		}
/*		for(i=1;i<=n;i++)
		{
			temp1=B[i];
			printf("%d: ",i);
			while(temp1!=NULL)
			{
				printf("%d ",temp1->data);
				temp1=temp1->next;
			}
			printf("\n");
		} */
		for(i=1;i<=n;i++)
		{
			if(check_list[i]==0)
			{
				count=1;
		//		printf("dfs called for %d\n",i);
				dfs(i);
//				printf("i: %d\n",i);
		//		printf("count: %d\n",count);
				if(count==n)
				{
					winner=i;
					break;
				}
			} 
			for(k=1;k<1005;k++)
				visited[k]=0;
		}
		if(i!=n+1)
		{
			win=0;
			count=0;
			for(i=1;i<=n;i++)
				visited[i]=0;
		//	printf("reverse dfs called for %d\n",winner);
			reverse_dfs(winner);
		//	printf("count: %d\n",count);
			win+=count;
			printf("%d\n",win);
		}
		else
			printf("0\n");
	}
	return 0;
}
