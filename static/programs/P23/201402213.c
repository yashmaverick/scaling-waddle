#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node *next;
}node;
node *v[1000000];
int order[1000000];
int heap[1000000],heapsize=0;
void insert(int i)
{
	heapsize++;
	heap[heapsize]=i;
	int temp=heapsize;
	while(temp>=1&&heap[temp/2]>heap[temp])
	{
		int temp2=heap[temp];
		heap[temp]=heap[temp/2];
		heap[temp/2]=temp2;
		temp/=2;
	}
}
int deletel()
{
	int retval=heap[1];
	heap[1]=heap[heapsize];
	heapsize--;
	int p=1;
	while(((p<<1)<=heapsize&&heap[p<<1]<heap[p])||((p<<1)+1<=heapsize&&heap[(p<<1)+1]<heap[p]))
	{
		int temp=heap[p];
		if(heap[(p<<1)]<heap[(p<<1)+1]||(p<<1)+1>heapsize)
		{
			heap[p]=heap[p<<1];
			heap[p<<1]=temp;
			p=(p<<1);
		}
		else
		{
			heap[p]=heap[(p<<1)+1];
			heap[(p<<1)+1]=temp;
			p=(p<<1)+1;
		}
	}
	return retval;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<1000000;i++)
	{
		v[i]=NULL;
		order[i]=0;
	}
	for(i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		node *newptr=(node *)malloc(sizeof(node));
		newptr->val=y;
		newptr->next=v[x];
		v[x]=newptr;
		order[y]++;
	}
	for(i=1;i<=n;i++)
		if(order[i]==0)
			insert(i);
	int j=0,popped;
	while(heapsize>0)
	{
		j++;
		popped=deletel();
		if(j<n)
			printf("%d ",popped);
		node *temp=v[popped];
		while(temp!=NULL)
		{
			order[temp->val]--;
			if(order[temp->val]==0)
				insert(temp->val);
			temp=temp->next;
		}
	}
	printf("%d\n",popped);
	return 0;
}
