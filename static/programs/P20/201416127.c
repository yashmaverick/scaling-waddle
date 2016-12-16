#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int visited[1000001],count[1000001];
void cleanslateprotocol(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		visited[i]=count[i]=0;
	}
}
struct node *a[1000001];
void insert(int l,int m,int n)
{
	if((l>=1 && l<=n)&&(m>=1 && m<=n))
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		struct node *head;
		head=a[l];
		temp->data=m;
		temp->next=NULL;
		if(head==NULL)
		{
			a[l]=temp;
		}
		else
		{
			temp->next=a[l];
			a[l]=temp;
		}
		struct node *tem=(struct node*)malloc(sizeof(struct node));
		head=a[m];
		tem->data=l;
		tem->next=NULL;
		if(head==NULL)
		{
			a[m]=tem;
		}
		else
		{
			tem->next=a[m];
			a[m]=tem;
		}
	}
}
void display(int n)
{
	int i;
	struct node* root;
	for(i=1;i<=n;i++)
	{
		root=a[i];
		printf("%d->",i);
		while(root->next!=NULL)
		{
			printf("%d ",root->data);
			root=root->next;
		}
		printf("\n");
	}
}
void dfs(int v,int visited[],int count[])
{
	visited[v]=1;
	struct node* root=(struct node*)malloc(sizeof(struct node*));
	root=a[v];
	while(root!=NULL)
	{
		if(root->data!=0)
		{
			if(visited[root->data]==0)
			{
				count[root->data]=count[v]+1;
				dfs(root->data,visited,count);
			}
		}
		root=root->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,j,l,m;
		int max=0;
		int node;
		for(i=1;i<=n;i++)
		{
			a[i]=(struct node*)malloc(sizeof(struct node));
			a[i]->data=0;
			a[i]->next=NULL;
		}
		if(n>1)
		{
			for(i=1;i<n;i++)
			{
				scanf("%d%d",&l,&m);
				insert(l,m,n);
			}
		//	display(n);
			cleanslateprotocol(n);
			dfs(l,visited,count);
			for(i=1;i<=n;i++)
			{
			//	printf("%d->",count[i]);
				if(count[i]>=max)
				{
					max=count[i];
					node=i;
				}
			}
			//printf("%d ",node);
			max=0;
			cleanslateprotocol(n);
			dfs(node,visited,count);
			for(i=1;i<=n;i++)
			{
				if(count[i]>max)
					max=count[i];
			}
		}
		if(n>0)
			printf("%d\n",max+1);
	}
	return 0;
}
