#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct adj_list
{
	int val;
	struct adj_list *next;
};
struct adj_list *a[1000000];
void f(int i);
void print();
void insert(int n, int k);
int n;
int count[1000000],vis[1000000],i2;

//memset(vis,-1,sizeof(vis));

int main()
{
	
memset(vis,-1,sizeof(vis));
	int t,i4;
	scanf("%d",&t);
	while(t--)
	{	

		i2=1;
		int i,k1,k2;
		scanf("%d",&n);
		if(n>0)
		{
			for(i=1;i<n;i++)
			{
				scanf("%d%d",&k1,&k2);
				if(k1>0&&k2>0)
				insert(k1,k2);
			}
			for(i=0;i<=n;i++)
			{
				count[i]=0;
				vis[i]=0;
			}
			//	print();
			f(1);
			for(i=0;i<=n;i++)
			{
				count[i]=0;
				vis[i]=0;
			}
			f(i2);
		}
		int max=0;
		for(i=1;i<=n;i++)
		{
			if(max<count[i])
				max=count[i];
		}
		printf("%d\n",max+1);
	for(i4=1;i4<=n;i4++)
	{
		a[i4]=NULL;
	//	a[i4]->next=NULL;
	}
	}
	return 0;
}
void insert(int n , int k)
{
	struct adj_list *temp;
	struct adj_list *root;
	root=a[n];
	temp=(struct adj_list*)malloc(sizeof(struct adj_list));
	temp->val=k;
	temp->next=NULL;
	if(root==NULL)
	{
		a[n]=temp;
	}
	else
	{
	temp->next=root->next;
	root->next=temp;
	}
	struct adj_list *temp1;
	struct adj_list *root1;
	root1=a[k];
	temp1=(struct adj_list*)malloc(sizeof(struct adj_list));
	temp1->val=n;
	temp1->next=NULL;
	if(root1==NULL)
	{
		a[k]=temp1;
	}
	else
	{
	temp1->next=root1->next;
	root1->next=temp1;
	}
}
void print()
{      int i;
	struct adj_list *root;//(struct adj_list*)malloc(sizeof(struct adj_list));
	for(i=1;i<=n;i++)
	{
		root=a[i];
		while(root!=NULL)

		{
			printf("%d->%d ",i,root->val);
			root=root->next;
		}
		printf("\n");
	}
}
void f(int i)
{
	//	printf("aagaya" );
	vis[i]=1;
		//printf("%d ",i);
	struct adj_list *root;
	root=a[i];
	while(root!=NULL)
	{
		if(root!=NULL&&vis[root->val]!=1)
		{
			count[root->val]=count[i]+1;
			i2=root->val;
			f(root->val);
		}
		root=root->next;
	}
}
