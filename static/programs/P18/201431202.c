#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *a[1001],*b[1001];

int vis[1001]={};

NODE *insert(NODE *root,int data) // can be used for stack as well and obviously graph insertion
{
	NODE *temp;
	temp=malloc(sizeof(NODE));
	temp->data=data;
	temp->next=root;
	root=temp;
	return root;
}

void print(NODE *root) //graph printing also can be used for stack printing
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	return ;
}

int ar[1000]={},size=0,count=1;

void dfs(int src,int se)
{
	if(vis[src]==1)
		return ;
	vis[src]=1;
	NODE *temp;
	if(se==1)
		temp=a[src];
	else
		temp=b[src];

	while(temp!=NULL)
	{
		if(vis[temp->data]==0)
		{
			count++;
			dfs(temp->data,se);
		}
		temp=temp->next;
	}
	return ;
}

int main()
{
	int t,flag=0;
	int n,i,m,j,vertex,k,l,o,count1=0;
	scanf("%d",&t);
	for(l=1;l<=t;l++)
	{
		flag=0;
		count1=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			a[i]=NULL;
			b[i]=NULL;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(k=1;k<=m;k++)
			{
				scanf("%d",&vertex);
				a[vertex]=insert(a[vertex],i);
				b[i]=insert(b[i],vertex);
			}
		}
		for(i=1;i<=n;i++)
		{
			count=1;
			dfs(i,1);
			if(count==n)
			{
				flag=1;
				break;
			}
			else
			{
				for(o=1;o<=n;o++)
				{
					vis[o]=0;
				}
			}
		}
		if(flag==1)
		{
			for(o=1;o<=n;o++)
				vis[o]=0;
			count=0;
			dfs(i,0);
			printf("%d\n",count+1);
		}
		else
			printf("0\n");
	}
	return 0;
}
