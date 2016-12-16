#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int visited[1000001],b[1000001];
int point;
void cleanslateprotocol(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
}
struct node *a[1000001];
void insert(int l,int m,int n)
{
	if((l>=1 && l<=n)&&(m>=1 && m<=n))
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		struct node *head;
		temp->data=m;
		temp->next=a[l];
		a[l]=temp;
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

void dfs(int v,int visited[])
{
	if(visited[v]==0)
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
					//		b[point]=root->data;
					//		point++;
					dfs(root->data,visited);
				}
			}
			root=root->next;
		}
		if(visited[v]==1)
		{
			b[point]=v;
			point++;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
		a[i]=(struct node*)malloc(sizeof(struct node));
		a[i]->data=0;
		a[i]->next=NULL;
	}
	int l,p;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&p);
		insert(l,p,n);
	}
//	display(n);
	point=0;
	i=n;
	while(i!=0)
	{
		dfs(i,visited);
		i--;
	}
	while(point--)
	{
		printf("%d",b[point]);
		if(point!=0)
			printf(" ");
	}
	printf("\n");
	return 0;
}

