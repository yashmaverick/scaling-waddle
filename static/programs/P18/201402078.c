#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
node *a[1001],*b[1001];
int visited[1001];
void inserta(int y,int x)
{
	node *new=malloc(sizeof(node));
	new->val=y;
	new->next=a[x];
	a[x]=new;
}
void insertb(int x,int y)
{
	node *new=malloc(sizeof(node));
	new->val=y;
	new->next=b[x];
	b[x]=new;
}
void dfsa(int q)
{
	node* p;
	p=a[q];
	visited[q]=1;
	while(p!=NULL)
	{
		int src=p->val;
		if (visited[src]==0)
			dfsa(src);
		p=p->next;
	}
}
void dfsb(int q)
{
	node* p;
	p=b[q];
	visited[q]=1;
	while(p!=NULL)
	{
		int src=p->val;
		if (visited[src]==0)
			dfsb(src);
		p=p->next;
	}
}
int main()
{
	int t,i,j,l;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d",&n);
		for(i=1;i<=1000;i++)
			a[i]=b[i]=NULL;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&l);
				inserta(i,l);
				insertb(i,l);
			}
		}
		int count=0;
		for(i=1;i<=n;i++)
		{
			int flag=0;
			for(j=1;j<=n;j++)
				visited[j]=0;
			dfsa(i);
			for(j=1;j<=n;j++)
				if(visited[j]==0)
				{
					flag=1;
					break;
				}
			if(flag==0)
			{
				for(j=1;j<=n;j++)
					visited[j]=0;
				dfsb(i);
				for(j=1;j<=n;j++)
				{
					if(visited[j]==1)
						count++;
				}
				break;
			}
		}
				printf("%d\n",count);
	}
	return 0;
}
