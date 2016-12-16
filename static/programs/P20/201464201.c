#include<stdio.h>
#include<stdlib.h>
int reach[1000006];
typedef struct linklist
{
	int data;
	struct linklist *next;
	struct linklist *next1;
}node;

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
int max,dest,count;
node *top;
void dfs(node *q,node *head[],int n)
{
	int i=1;
	reach[q->data]=1;
	top=q;
	q=q->next;
	count=1;
	int p=1;
	while(top!=NULL && q!=NULL)
	{
		//printf("%d\n",i);
	//	p++;
		if(reach[q->data]==1)
		{
			q=q->next;
		}
		else
		{
			count++;
		//	printf("c%d n%d\n",count,q->data);
			if(count>max)
			{
				max=count;
				dest=q->data;
			}
			reach[q->data]=1;
			i++;
			q=head[q->data];
			q->next1=top;
			top=q;
			q=q->next;
		}
		if(q==NULL)
		{
			count--;
			top=top->next1;
			q=top;
		//	printf("c%d n%d\n",count,q->data);
		}
		if(i>=n)
		{
			break;
		}
//		printf("top%d\n",top->data);
	}
}
int main()
{
	int e,n,p,q,i,j,test,t,count,maincount,war,nowar,x,flag,war2,depth;
	node *temp;
	node *head[1000003];
	scanf("%d", &test);
	for(t=0;t<test;t++)
	{
		top=NULL;
		max=0;
		count=1;
		flag=0;
		maincount=0;
		maincount=0;
		/*	for(i=0;i<1000003;i++)
			{
			head[i]=NULL;
			reach[i]=0;
			}*/
		scanf("%d", &n);
		for(j=1;j<=n;j++)
		{
			head[j]=NULL;
			reach[j]=0;
		}
		for(j=1;j<n;j++)
		{
			scanf("%d %d", &war,&war2);
			head[war]=insert(head[war],war2);
			head[war2]=insert(head[war2],war);
		}
		for(j=1;j<=n;j++)
		{
			head[j]=insert(head[j],j);
		}
		if(n!=1)
		{
			dfs(head[1],head,n);
//		printf("%d\n", max);
		count=1;max=0;
		for(i=0;i<=n;i++)
		{
			reach[i]=0;
		}
		dfs(head[dest],head,n);
		printf("%d\n", max);
		}
		if(n==1)
		{
			printf("1\n");
		}
	}
	return 0;
}


