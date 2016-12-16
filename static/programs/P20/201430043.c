#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct node{
	int value;
	struct node *next;
}node;

int max=0,vis[1000007],r,count;
node * l[1000007];

void List(int x,int y)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->value=y;
	p->next=NULL;
	if(l[x]!=NULL)
		p->next=l[x];
	l[x]=p;

	p=(node *)malloc(sizeof(node));
	p->value=x;
	p->next=NULL;
	if(l[y]!=NULL)
		p->next=l[y];
	l[y]=p;
}

void longest_path(node *head)
{
        while(head!=NULL)
        {
		if(vis[head->value]==0)
		{
			count++;
			if(count>max)
			{
				max=count;
				r=head->value;
			}
			vis[head->value]=1;
			longest_path(l[head->value]);
		}
		head=head->next;
	}
	count--;
}

int main()
{
	int i,j=0,t,n,x,y,f;
	scanf("%d",&t);
	node *temp;
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			l[i]=NULL;
		if(n==0)
			printf("0\n");
		else if(n==1)
			printf("1\n");
		else
		{
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			List(x,y);
		}
		for(i=1;i<=n;i++)
			vis[i]=0;
		temp=(node *)malloc(sizeof(node));
		temp->value=x;
		temp->next=NULL;
		max=0;
		count=0;
		longest_path(temp);
		for(i=0;i<=n;i++)
			vis[i]=0;
		temp=(node *)malloc(sizeof(node));
		temp->value=r;
		temp->next=NULL;
		max=0;
		count=0;
		longest_path(temp);
		printf("%d\n",max);
		}
	}
	return 0;
}
