#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	struct node *next;
}node;
node *head[1000000];
int heap[1000000],nheap,indeg[1000000],mark[1000000],value[1000000];
void sup(int p)
{
	int temp,i;
	i=p;
	while(heap[i]<heap[i/2])
	{
		if(i==1)
		{
			break;
		}
		temp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=temp;
		i=i/2;
	}
}
void sdown(int p)
{
	int i,temp;
	i=p;
	if(2*i>nheap)
	{
		return;
	}
	else
	{
		while((heap[i]>heap[2*i])||(heap[i]>heap[2*i+1]))
		{
			if(heap[2*i]<heap[2*i+1])
			{
				temp=heap[2*i];
				heap[2*i]=heap[i];
				heap[i]=temp;
				i=2*i;
			}
			else
			{
				temp=heap[2*i+1];
				heap[2*i+1]=heap[i];
				heap[i]=temp;
				i=2*i+1;
			}
			if(2*i>nheap)
			{
				break;
			}
		}
	}

}
int rem()
{
	int val;
	val=heap[1];
	heap[1]=heap[nheap];
	nheap=nheap-1;
	sdown(1);
	return val;
}

void update(int i,int x)
{
	heap[i]=x;
	sup(i);
	sdown(i);
}

void insert(int y,int x)
{
	node *p;
	p=(node *)(malloc(sizeof(node)));
	p->value=x;
	p->next=NULL;
	indeg[x]++;
	if(head[y]==NULL)
	{
		head[y]=p;
		return;
	}
	else
	{
		p->next=head[y];
		head[y]=p;
	}
}

void display(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
}
void disheap()
{
	int i;
	for(i=1;i<=nheap;i++)
	{
		printf("%d ",heap[i]);
	}
	printf("\n");
}
void inheap(int x)
{
	nheap=nheap+1;
	heap[nheap]=x;
	sup(nheap);
}

int main()
{
	int x,y,m,n;
	int i,j,t;
	node *temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		insert(x,y);
	}
/*	for(i=1;i<=n;i++)
	{
		printf("%d->",i);
		display(head[i]);
		printf("\n");
	}
	t=1;
	printf("indeg:");
	for(i=1;i<=n;i++)
	{
		printf("%d ",indeg[i]);
	}
	printf("\n");*/
	for(i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		{
			inheap(i);
			mark[i]=1;
		}
	}
	node *p;
	j=0;
	while(nheap>0)
	{
		x=rem();
		value[j++]=x;
	//	printf("%d ",x);
		p=head[x];
		while(p!=NULL)
		{
			if(mark[p->value]!=1)
			{
				indeg[p->value]--;
				if(indeg[p->value]==0)
				{
					inheap(p->value);
					mark[p->value]=1;
				}
			}
			p=p->next;
		}
//		disheap();
	}
	for(i=0;i<j-1;i++)
	printf("%d ",value[i]);
	printf("%d\n",value[i]);
//	printf("%d\n",heap[1]);
	return 0;
}
