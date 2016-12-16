#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

node *head[1000005];
int dep[1000005];
int heap[1000005];
node * insert(node *root,int l)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=l;
	temp->next=root;
	return temp;
}

int num_heap=0;

void swap(int a,int b)
{
	int temp=heap[a];
	heap[a]=heap[b];
	heap[b]=temp;
}

void insert_heap(int num)
{
	num_heap++;
	int k=num_heap;
	heap[k]=num;
	while(heap[k/2]>heap[k] && k>1)
	{
		swap(k,k/2);
		k=k/2;
	}
}

int pop()
{
	int var=heap[1];
	heap[1]=heap[num_heap];
	num_heap--;
	int pos=1;
	while((heap[2*pos]<heap[pos]  && 2*pos<=num_heap) || (heap[(2*pos)+1]<heap[pos]) && (2*pos)+1<=num_heap)
	{
		if(heap[2*pos]<heap[(2*pos)+1])
		{
			swap(pos,2*pos);
			pos=2*pos;
		}
		else
		{
			swap(pos,(2*pos)+1);
			pos=(2*pos)+1;
		}
	}
	node *temp=head[var];
	while(temp!=NULL)
	{
		//temp=temp->next;
		dep[temp->data]--;



		if(dep[temp->data]==0)
		{
			insert_heap(temp->data);
		}
		temp=temp->next;
	}
	return var;
}


int main()
{
	int n,e,j,i;
	scanf("%d%d",&n,&e);
	while(e--)
	{
		int l,k;
		scanf("%d%d",&l,&k);
		dep[k]++;
		head[l]=insert(head[l],k);
	}

	for(i=1;i<=n;i++)
	{
		if(dep[i]==0)
			insert_heap(i);
		
	}
/*	for(i=1;i<10;i++)
	{
		node *temp=head[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}*/
	while(num_heap>0)
	{
		int a=pop();
		if(num_heap==0)
			printf("%d\n",a);
		else
			printf("%d ",a);
	}
	return 0;
}
		
