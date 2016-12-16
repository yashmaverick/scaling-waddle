#include<stdio.h>
#include<stdlib.h>

int H[1000009],total[1000009]={0};

typedef struct node
{
	int value;
	struct node *next;
}node;

int size=0;
node *D[1000009];

void heap_insert(int val)
{
	int x;
	size++;
	H[size]=val;
	x=size;
	while(H[x/2]>val)
	{
		H[x]=H[x/2];
		x=x/2;
	}
	H[x]=val;
	return ;
}

void heap_delete(int a)
{
	if(2*a>size)
	{
		return ;
	}
	if(2*a==size)
	{
		if(H[2*a]<H[a])
		{
			int z=H[a];
			H[a]=H[2*a];
			H[2*a]=z;
			heap_delete(2*a);
			return ;
		}
	}
	if(2*a+1<=size)
	{
		if(H[2*a]<=H[2*a + 1])
		{
			if(H[a]>H[2*a])
			{
				int x=H[a];
				H[a]=H[2*a];
				H[2*a]=x;
				heap_delete(2*a);
				return ;
			}
		}
		if(H[2*a]>H[2*a + 1])
		{
			if(H[a]>H[2*a + 1])
			{
				int y=H[a];
				H[a]=H[2*a + 1];
				H[2*a + 1]=y;
				heap_delete(2*a + 1);
				return ;
			}
		}
		return ;
	}
}

int main()
{
	int m,i,y,x,a,b,count,j;
	scanf("%d %d",&x,&y);
	m=y;
	H[0]=-1000000000;
	while(y--)
	{
		scanf("%d %d",&a,&b);
		node *z=(node *)malloc(sizeof(node));
		z->value=b;
		z->next=D[a];
		D[a]=z;
		total[b-1]++;
	}
	for(i=0;i<x;i++)
	{
		if(total[i]==0)
		{	
			heap_insert(i+1);
		}
	}
	for(i=0;i<x;i++)
	{
		node *temp;
		temp=D[H[1]];
		if(i==x-1)
		{
			printf("%d",H[1]);
		}
		else
		{
			printf("%d ",H[1]);
		}
		H[1]=H[size];
		size=size-1;
		heap_delete(1);
		while(temp!=NULL)
		{
			total[temp->value-1]--;
			if(total[temp->value-1]==0)
			{
				heap_insert(temp->value);
			}
			temp=temp->next;
		}
	}
	printf("\n");
	return 0;
}
