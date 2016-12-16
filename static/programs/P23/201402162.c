#include<stdio.h>
#include<stdlib.h>
#define MAX 100000000;
typedef struct data{
	int val;
	struct data* next;
}data;
int count;
int heap[1000001];
data* head[1000001];
int connect[1000001]={0};
void insert(int value)
{
	count++;
	heap[count]=value;
	int a,temp;
	a=count;
	while(heap[a]<heap[a/2] && a>1)
	{
		temp=heap[a];
		heap[a]=heap[a/2];
		heap[a/2]=temp;
		a=a/2;
	}
}
void delmin()
{
	heap[1]=heap[count];
	heap[count]=MAX;
	count--;
	int a,temp;
	a=1;
	while((heap[a]>heap[(2*a)]  || heap[a]>heap[(2*a)+1]) && (2*a<=count))
	{
		if(heap[(2*a)]<heap[(2*a)+1])
		{
			temp=heap[a];
			heap[a]=heap[(2*a)];
			heap[(2*a)]=temp;
			a=2*a;
		}
		else
		{
			temp=heap[a];
			heap[a]=heap[(2*a)+1];
			heap[(2*a)+1]=temp;
			a=(2*a)+1;
		}
	}
}
int main()
{
	int i,n,m,u,v;
	data* itr;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		heap[i]=MAX;
		head[i]=NULL;
	}
	while(m--)
	{
		scanf("%d%d",&u,&v);
		itr=(data*)malloc(sizeof(data));
		itr->val=v;
		itr->next=head[u];
		head[u]=itr;
		connect[v]+=1;
	}
	count=0;
	for(i=1;i<=n;i++)
	{
		if(connect[i]==0)
			insert(i);
	}
	i=0;
	while(count>0)
	{
		int value;
		value=heap[1];
		itr=head[value];
		i++;
		if(i!=n)
			printf("%d ",heap[1]);
		else
			printf("%d\n",heap[1]);
		delmin();
		while(itr!=NULL)
		{
			connect[itr->val]=connect[itr->val]-1;
			if(connect[itr->val]==0)
				insert(itr->val);
			itr=itr->next;
		}
	}
	return 0;
}
