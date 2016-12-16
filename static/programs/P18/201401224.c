#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}node;
int d[1002],q;
void dfs(struct node* a[1002],int k,int c[1002])
{
	int y;
	struct node *head;
	head=a[k];
	d[k]=1;
	q=q+1;
	while(head!=NULL&&c[k]!=0)
	{
		y=head->data;
		if(d[y]==0)
			dfs(a,y,c);
		head=head->next;
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j,k,x,g,c[1002],e[1002];
		struct node *a[1002];
		struct node *b[1002];
		struct node *head;
		scanf("%d",&n);
		for(j=1;j<n+1;j++)
		{
			a[j]=(struct node *)malloc(sizeof(struct node));
			a[j]->next=NULL;
			b[j]=(struct node *)malloc(sizeof(struct node));
			b[j]->next=NULL;
			c[j]=0;
			e[j]=0;
		}
		for(j=1;j<=n;j++)
		{
			scanf("%d",&g);
			for(k=0;k<g;k++)
			{
				scanf("%d",&x);
				head=(struct node *)malloc(sizeof(struct node));
				if(c[j]==1)
				{
					head->next=a[j]->next;
					head->data=a[j]->data;
					a[j]->data=x;
					a[j]->next=head;
				}
				else
				{
					a[j]->data=x;
					c[j]=1;
				}
				head=(struct node *)malloc(sizeof(struct node));
				if(e[x]==1)
				{
					head->next=b[x]->next;
					head->data=b[x]->data;
					b[x]->data=j;
					b[x]->next=head;
				}
				else
				{
					b[x]->data=j;
					e[x]=1;
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			q=0;
			for(k=1;k<=n;k++)
				d[k]=0;
			dfs(b,j,e);
			if(q==n)
				break;
		}
		q=0;
		for(k=1;k<=n;k++)
			d[k]=0;
		//printf("%d ",j);
		if(j<=n)
			dfs(a,j,c);
		printf("%d\n",q);
	}
	return 0;
}
