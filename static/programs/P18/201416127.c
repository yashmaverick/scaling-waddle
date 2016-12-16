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
		visited[i]=0;
		count[i]=0;
	}
}
struct node *a[1000001],*b[1000001];
void insert(int l,int m,int n)
{
	if((l>=1 && l<=n)&&(m>=1 && m<=n))
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		struct node *head;
		//head=a[l];
		temp->data=m;
		temp->next=a[l];
		a[l]=temp;
		/*temp->next=NULL;
		if(head==NULL)
		{
			a[l]=temp;
		}
		else
		{
			temp->next=a[l];
			a[l]=temp;
		}*/
		struct node *tem=(struct node*)malloc(sizeof(struct node));
		head=b[m];
		tem->data=l;
		tem->next=NULL;
		if(head==NULL)
		{
			b[m]=tem;
		}
		else
		{
			tem->next=b[m];
			b[m]=tem;
		}
	}
}
void display(int n)
{
	int i;
	struct node* root;
	for(i=1;i<=n;i++)
	{
		root=b[i];
		printf("%d->",i);
		while(root->next!=NULL)
		{
			printf("%d ",root->data);
			root=root->next;
		}
		printf("\n");
	}
}
int sum;
void dfs(int v,int visited[],int count[])
{
	visited[v]=1;
	struct node* root=(struct node*)malloc(sizeof(struct node*));
	root=b[v];
	while(root!=NULL)
	{
		if(root->data!=0)
		{
			if(visited[root->data]==0)
			{
				count[root->data]=count[v]+1;
				sum++;
				dfs(root->data,visited,count);
			}
		}
		root=root->next;
	}
}
void dfsi(int v,int visited[],int count[])
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
				sum++;
				//printf("%d->",root->data);
				dfsi(root->data,visited,count);
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
		struct node* temp;
		for(i=1;i<=n;i++)
		{
			a[i]=(struct node*)malloc(sizeof(struct node));
			a[i]->data=0;
			a[i]->next=NULL;
			b[i]=(struct node*)malloc(sizeof(struct node));
			b[i]->data=0;
			b[i]->next=NULL;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&l);
				insert(i,l,n);
			}
		}
		/*
		for(i=1;i<=n;i++)
		{
			printf("%d : ",i);
			temp=a[i];
			while(temp!=NULL){
				printf("%d ",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}
		
		for(i=1;i<=n;i++)
		{
			printf("%d : ",i);
			temp=b[i];
			while(temp!=NULL){
				printf("%d ",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}*/
		//	display(n);
		for(i=1;i<=n;i++)
		{
			sum=1;
			cleanslateprotocol(n);
			dfs(i,visited,count);
			if(sum==n)
				break;
		}
		
		if(i>n)
		{
			printf("0\n");
		}
		else
		{
			//	printf("%d\t",i);
			/*for(i=1;i<=n;i++)
			  {
			  if(count[i]>max)
			  {
			  max=count[i];
			  node=i;
			  }
			  }*/
			sum=1;
			cleanslateprotocol(n);
			dfsi(i,visited,count);
			printf("%d\n",sum);
		}
	}
	return 0;
}
