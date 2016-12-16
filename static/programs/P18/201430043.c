#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct node{
	int value;
	struct node *next;
}node;

int count,V[1000007];
node * L1[1000007],*L2[1000007];

void List1(int w,int l)
{
	struct node *p;
	p=(node *)malloc(sizeof(node));
	p->value=l;
	p->next=NULL;
	if(L1[w]!=NULL)
		p->next=L1[w];
	L1[w]=p;
}

void List2(int l,int w)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->value=w;
	p->next=NULL;
	if(L2[l]!=NULL)
		p->next=L2[l];
	L2[l]=p;
}

void DFS(node *head,int flag)
{
        while(head!=NULL)
        {
		if(V[head->value]==0)
		{
			count++;
			V[head->value]=1;
			if(flag==0)
				DFS(L1[head->value],flag);
			else
				DFS(L2[head->value],flag);
		}
		head=head->next;
	}
}

int main()
{
	int i,j=0,t,n,w,l,m;
	scanf("%d",&t);
	node *temp;
	while(j<t)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			L1[i]=NULL;
			L2[i]=NULL;
		}
		
		for(l=1;l<=n;l++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&w);
				List1(w,l);
				List2(l,w);
			}
		}
		m=0;
		int flag=0;
		for(i=1;i<=n;i++)
		{

			for(l=1;l<=n;l++)
				V[l]=0;
			count=0;
			temp=(node *)malloc(sizeof(node));
			temp->value=i;
			temp->next=NULL;
			DFS(temp,flag);
			if(count==n)
			{
				m=i;
				break;
			}
		}

		if(m==0)
			printf("0\n");
		else
		{
		        flag=1;
			for(i=0;i<=n;i++)
				V[i]=0;
			temp=(node *)malloc(sizeof(node));
			temp->value=m;
			temp->next=NULL;
			count=0;
			DFS(temp,flag);
			printf("%d\n",count);
		}
		j++;
	}
	return 0;
}
