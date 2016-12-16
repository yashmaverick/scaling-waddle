#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *next;
}node;
long long int heap[100004];
int point;
void insertheap(int val)
{
	point++;
	heap[point]=val;
	int index=point;
	while(index>1)
	{
		if(heap[index]<heap[index/2])
		{
			int temp=heap[index];
			heap[index]=heap[index/2];
			heap[index/2]=temp;
		}
		index=index/2;
	}
}
void delete()
{

	heap[1]=heap[point];
	point--;
	int index=1;
	if(index>point)
		return;
	while(1)
	{

		int maxindex=2*index;
		if(maxindex>point)
			return;
		if(heap[maxindex]>heap[maxindex+1] && maxindex+1<=point)
		{
			maxindex++;
		}
		if(heap[index]>heap[maxindex])
		{
			int temp=heap[index];
			heap[index]=heap[maxindex];
			heap[maxindex]=temp;
		}
		index=maxindex;
		if(index>point)
			break;

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

int main()
{
	long long int n,m,i,j,k,dep[100003],count=0,temp,a,b;
	node *head[100004];
	scanf("%lld %lld", &n, &m);
	for(i=0;i<=n;i++)
	{
		dep[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld", &a,&b);
		head[a]=insert(head[a],b);
		dep[b]++;
	}
	for(i=1;i<=n;i++)
	{
		if(dep[i]==0)
		{
			insertheap(i);
		}
	}
	while(count<=n)
	{
	temp=heap[1];
	if(count<n-1)
		printf("%lld ", temp);
	else
		printf("%lld",temp);
	count++;
	if(count==n)
	{
		break;
	}
	delete();
	node *p;
	p=head[temp];
	while(p!=NULL)
	{
		dep[p->data]--;
		if(dep[p->data]==0)
		{
			insertheap(p->data);
		}
		p=p->next;
	}
	}
	printf("\n");
	return 0;
}

