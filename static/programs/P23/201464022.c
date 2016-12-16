#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long val;
	struct node *next;
}node;
long long int *count,*heap,*ans,mincount=0;
node *a;
void insertmin(long long int v1)
{
	mincount++;
	long long int i,temp,flag=0;
	i=mincount;
	heap[mincount]=v1;
	while(i>1)
	{
		if(heap[i]<heap[i/2])
		{
			flag=1;
			temp=heap[i];
			heap[i]=heap[i/2];
			heap[i/2]=temp;
		}
		if(flag==0)
			break;
		flag=0;
		i=i/2;
	}
}
void deletemin()
{
	long long int minindex,i,temp;
	heap[1]=heap[mincount];
	i=1;
	mincount--;
	int flag=0;
	while(i<=(mincount)/2)
	{
		if(heap[2*i]<heap[(2*i)+1])
			minindex=2*i;
		else minindex=(2*i)+1;
		if(heap[i]>heap[minindex])
		{
			flag=1;
			temp=heap[i];
			heap[i]=heap[minindex];
			heap[minindex]=temp;
		}
		if(flag==0)
			break;
		flag=0;
		i=minindex;
	}

}

void create(long long v1,long long v2)
{
	node *p=malloc(sizeof(node));
	p->val=v2;
	p->next=NULL;
	node *temp=&a[v1];
	if(temp->next==NULL)
		temp->next=p;
	else
	{
		p->next=temp->next;
		temp->next=p;
	}
}

int main()
{
	long long n,m,v1,v2,i,j,v;
	scanf("%lld%lld",&n,&m);
	count=malloc(sizeof(long long int)*(n+1));
	heap=malloc(sizeof(long long int)*(n+1));
	ans=malloc(sizeof(long long int)*(n+1));
	a=malloc(sizeof(node)*(n+1));
	for(i=0;i<=n;i++)
		count[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&v1,&v2);
		count[v2]++;
		create(v1,v2);
	}
	for(v=1;v<=n;v++)
	{
		if(count[v]==0)
			insertmin(v);
	}
	for(i=1;i<=n;i++)
	{
		v=heap[1];
		deletemin();
		ans[i]=v;
		node *temp=&a[v];
		while(temp->next!=NULL)
		{
			temp=temp->next;
			count[temp->val]--;
			if(count[temp->val]==0)
				insertmin(temp->val);
		}
	}
	for(i=1;i<n;i++)
		printf("%lld ",ans[i]);
	printf("%lld\n",ans[n]);
	return 0;
}








