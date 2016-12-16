#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	int val;
	struct ll *next;
}node;

node *ar[500005];
int ct[500005];
int heap[500005];
int ptr=1;
void deletemin()
{
	heap[1]=heap[ptr-1];
	ptr--;
	int x=1;
	while(x<ptr)
	{
		if(2*x+1>=ptr)
		{
			if(2*x<ptr)
			{
				if(heap[2*x]<heap[x])
				{
					int temp=heap[x];
					heap[x]=heap[2*x];
					heap[2*x]=temp;
					x=2*x;
				}
				else
					break;
			}
			else
				break;
		}
		else if(heap[x]<=heap[2*x] && heap[x]<=heap[2*x+1])
			break;
		else
		{
			if(heap[2*x]<=heap[2*x+1])
			{
				int temp=heap[x];
				heap[x]=heap[2*x];
				heap[2*x]=temp;
				x=2*x;
			}
			else
			{
				int temp=heap[x];
				heap[x]=heap[2*x+1];
				heap[2*x+1]=temp;
				x=2*x+1;
			}
		}
	}
}
void hinsert(int val);
void insert(int a,int b)
{
	ct[b]++;
	if(ar[a]==NULL)
	{
		ar[a]=(node *)malloc(sizeof(node));
		ar[a]->val=b;
	}
	else
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->val=b;
		temp->next=ar[a];
		ar[a]=temp;
	}
}//correct

int main()
{
	int n,m,i,j,k,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
		ct[i]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
	}//correct
	for(i=1;i<=n;i++)
	{
		if(ct[i]==0)
			hinsert(i);
	}
//	for(i=1;i<=n;i++)
//		printf("%d " ,ct[i]);
//	printf("ptr: %d",ptr);
	int ans[500005];
	int x=0;
	while(ptr>1)
	{
		int a=heap[1];
		deletemin();
		ans[x]=a;
		x++;
		node *temp=ar[a];
		while(temp!=NULL)
		{
			ct[temp->val]--;
			if(ct[temp->val]==0)
				hinsert(temp->val);
			temp=temp->next;
		}
	}
	for(i=0;i<x-1;i++)
		printf("%d ",ans[i]);
	printf("%d",ans[x-1]);
	printf("\n");
	return 0;
}

void hinsert(int val)//insert to heap
{
	heap[ptr]=val;
	int x=ptr;
	ptr++;
	while(x>1)
	{
		if(heap[x]>=heap[x/2])
			break;
		else
		{
			int temp=heap[x];
			heap[x]=heap[x/2];
			heap[x/2]=temp;
			x=x/2;
		}
	}
}
