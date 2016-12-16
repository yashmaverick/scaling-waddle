#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	long long int data;
	struct queue *next;
	struct queue *prev;
} node;

node *f;
node *b;

void pushb(int v)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	t->data=v;
	//printf("%d\n",v);
	if(b!=NULL)
	{
		t->next=b;
		b->prev=t;
		b=t;
	}
	else
	{
		t->next=NULL;
		b=t;
		f=b;
	//	printf("%d\n",f->data);
	}
	t->prev=NULL;
}

void popb()
{
	node *t;	
	t=b;
	b=b->next;
	if(b!=NULL)
		b->prev=NULL;
	else
		f=b;
	free(t);
}

void popf()
{
	node *t;
	t=f;
	f=f->prev;
	if(f!=NULL)
		f->next=NULL;
	else
		b=f;
	free(t);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k,i,a[100000];
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		b=NULL;
		f=b;
		for(i=0;i<k;i++)
		{
			if(f!=NULL)
				while(a[i]<=a[b->data])
				{
					popb();
					if(f==NULL)
						break;
				}
			pushb(i);
		}
		//printf("%d\n",b->data);
		for(i=k;i<n;i++)
		{
			printf("%lld ",a[f->data]);
			if(f!=NULL)
				while((f->data)<=i-k)
				{
					popf();
					if(f==NULL)
						break;
				}
			//printf("%d\n",a[f->data]);
			if(f!=NULL)
				while(a[i]<=a[b->data])
				{
					popb();
					if(f==NULL)
						break;
				}
			pushb(i);
		}
		printf("%lld\n",a[f->data]);
		free(b);
	}
	return 0;
}
