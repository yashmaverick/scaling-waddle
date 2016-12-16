#include<stdio.h>
#include<stdlib.h>
int reach[1006];
typedef struct linklist
{
	int data;
	struct linklist *next;
}node;
int front,rear,a[1000005];
void enqueue(int k)
{
	if(front==rear && front==-1)
	{
		front++;
		rear++;
		a[rear]=k;
	}
	else
	{
		rear++;
		a[rear]=k;
	}
}
void dequeue()
{
	if(front==rear && rear==-1)
	{
		return;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front++;
	}

}
void print()
{
	int k;
	if(front==rear && front==-1)
	{
		return;
	}
	else
	{
		for(k=front;k<=rear;k++)
		{
			printf("%d->", a[k]);
		}
		printf("\n");
	}
}
node *insert(node *head,int k)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=k;
	if(head==NULL)
	{
		head=p;
		return head;
	}
	else
	{
		p->next=head;
		head=p;
		return head;
	}
}
void dfs(node *q,node *head[])
{
	int i;
	reach[q->data]=1;
	while(q!=NULL)
	{
		if(reach[q->data]==0)
		{
			dfs(head[q->data],head);
		}
		q=q->next;
	}
}
int main()
{
	int e,n,p,q,i,j,test,b[1003][1004],t,count,maincount,war,nowar,x,flag;
	node *temp;
	node *head[1004];
	node *head1[10004];
	scanf("%d", &test);
	for(t=0;t<test;t++)
	{
		count=0;
		flag=0;
		maincount=0;
		front=-1;
		rear=-1;
		maincount=0;
		for(i=0;i<1002;i++)
		{
			head[i]=NULL;
			head1[i]=NULL;
			reach[i]=0;
			for(j=0;j<1002;j++)
			{
				b[i][j]=0;
			}
		}
		scanf("%d", &n);
		for(j=1;j<=n;j++)
		{
			scanf("%d", &nowar);
			b[j][0]=nowar;
			for(i=1;i<=nowar;i++)
			{
				scanf("%d", &war);
				head[war]=insert(head[war],j);
				head1[j]=insert(head1[j],war);
				b[j][i]=war;
			}
		}
		for(j=1;j<=n;j++)
		{
			head1[j]=insert(head1[j],j);
			head[j]=insert(head[j],j);
		}
	//	printf("%d\n",count);
		for(j=1;j<=n;j++)
		{
			dfs(head[j],head);
			for(i=1;i<=n;i++)
			{
				if(reach[i])
					count++;
				reach[i]=0;
			}
	//			printf("%d\n",count);
			if(count==n)
			{
			//	enqueue(j);
				flag=1;
				break;
			}
			count=0;
		}
//		print();
		count=0;
		if(flag==1)
		{
			
			dfs(head1[j],head1);
			for(i=1;i<=n;i++)
			{
				if(reach[i])
				{
					count++;
				}
				reach[i]=0;
			}
			maincount=count;
		}
		printf("%d\n",maincount);
	}
	return 0;
}


