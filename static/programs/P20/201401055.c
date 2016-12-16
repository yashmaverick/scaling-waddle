#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};
struct node * l[1000005];
int path=0;
int count,m1_long;
int visited[1000005];


void dfs(struct node *head)
{

        while(head!=NULL)
        {
		if(visited[head->data]==0)
		{
			count++;
			if(count>path)
			{
				path=count;
				m1_long=head->data;
			}
			visited[head->data]=1;
			dfs(l[head->data]);
		}
		head=head->next;
	}
	count=count-1;
}

void adjlist(int m1,int m2)
{
	struct node *p,*p1;
	p=(struct node *)malloc(sizeof(struct node));
	p1=(struct node *)malloc(sizeof(struct node));

	p->data=m2;
	p->next=NULL;
	if(l[m1]!=0)
		p->next=l[m1];
	l[m1]=p;

	
	p1->data=m1;
	p1->next=NULL;
	if(l[m2]!=0)
		p1->next=l[m2];
	l[m2]=p1;
}

int main()
{
	int i,j=0,t,n,m1,m2,f;
	scanf("%d",&t);
	struct node *temp;
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			l[i]=NULL;
		if(n==1)
			printf("1\n");
		else if(n==0)
			printf("0\n");
		else
		{
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&m1,&m2);
			adjlist(m1,m2);
		}
		int k;
		for(i=0;i<=1;i++)
		{
			for(k=1;k<=n;k++)
				visited[k]=0;
			temp=(struct node *)malloc(sizeof(struct node));
			if(i==0)
				temp->data=m1;
			if(i==1)
				temp->data=m1_long;
			temp->next=NULL;
			path=0;
			count=0;
			dfs(temp);
			if(i==1)
				printf("%d\n",path);
		}
		
		}
		
	}
	return 0;
}
