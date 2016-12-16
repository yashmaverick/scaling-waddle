#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node;
struct node* head[1000000];
int v[1000000];
int leaf;
/*struct node* create(int value)
{
	node* p=(node*)malloc(sizeof(node));
	p->data=value;
	p->next=NULL;
	return p;
}*/
struct node* create();
void insert();
void print();
void print1();
int count,n,count_max;
void  max();
int main()
{
	int m,t;
	int i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		count=count_max=0;
		//count_max=count;
		//printf("count=%d\n",count);
	scanf("%d",&n);
	if(n>1)
	{
	for(i=1;i<=n;i++)
	{
		head[i]=NULL;
		v[i]=1;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		insert(a,b);
	}
	//print();
	node* q=create(head[1]->data);
	max(q);
	for(i=1;i<=n;i++)
		v[i]=1;
	//printf(:"%d",leaf);
	q=create(leaf);
	count=count_max=0;
	max(q);
	}
	else if(n==1)
		count_max=0;
	printf("%d\n",count_max);
	}
return 0;
}
struct node* create(int value)
{
	node* q=(node*)malloc(sizeof(node));
	q->data=value;
	q->next=NULL;
	return q;
}
void   max(struct node* q)
{
	//printf("enterance=%d\n",q->data);
	int i;
	node* p;
	while(q!=NULL)
	{
		if(v[q->data]==0) 
			q=q->next;
		//if(v[q->data]==0)
		else
		{
			v[q->data]=0;
			count++;
		if(count_max<=count)
		{
			count_max=count;
			leaf=q->data;
		}
		max(head[q->data]);
		q=q->next;
		}
	}
	count--;
	return;
}
void insert(int a,int b)
{
	//node* q=(node*)malloc(sizeof(node));
	//q->data=b;
	node*q;
	//q->next=NULL;
	q=create(b);
	if(head[a]==NULL) 
	{
		head[a]=q;
		//printf("hii\n");
	}
	else
	{
		q->next=head[a];
		head[a]=q;
	}

	q=(node*)malloc(sizeof(node));
	//q->data=a;
	//q->next=NULL;
	q=create(a);
	if(head[b]==NULL)
	{
		head[b]=q;
		//printf("hii\n");
	}
	else
	{
		q->next=head[b];
		head[b]=q;
	}
	return;
}
void print(int n)
{
	int i;
	node *q;
	for(i=1;i<=n;i++)
	{
		q=head[i];
		printf("%d->",i);
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->next;
		}
		printf("\n");
	}
	return;
}
void print1(int a)
{
	node* q;
	q=head[a];
	printf("%d->",a);
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
	return;
}
