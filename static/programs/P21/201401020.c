#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	long long int data,wt;
	struct node *next;
}node;

node *head[100005];
//	int val;

node *insert(node *root,long long int n,long long int w)
{
	node *temp=malloc(sizeof(node));
	temp->data=n;
	temp->wt=w;
	temp->next=root;
	return temp;
}

long long int status[100005],dis[100005];
long long int heap[100005],rev[100005],revrev[100005];
long long int num_heap=0;


void swap(long long int a,long long int b)
{
	revrev[rev[a]]=b;
	revrev[rev[b]]=a;
	
	long long int temp=heap[a];
	heap[a]=heap[b];
	heap[b]=temp;

	temp=rev[a];
	rev[a]=rev[b];
	rev[b]=temp;
}

void insrt(long long int n)
{
	num_heap++;
	heap[num_heap]=dis[n];
	rev[num_heap]=n;
	revrev[n]=num_heap;
	long long int l=num_heap;
	while(heap[l/2]>heap[l] && l>1)
	{
		swap(l,l/2);
//		revrev[rev[l]]=l/2;
//		revrev[rev[l]]=l/2;
		l=l/2;
	}
}


void dec(long long int n)
{
/*	long long int i;
	for(i=1;i<=num_heap;i++)
	{
		if(rev[i]==n)
		{
			n=i;
			break;
		}
	}       */
	n=revrev[n];
	heap[n]=dis[rev[n]];

	while(heap[n/2]>heap[n] && n>1)
	{
		swap(n,n/2);
		n=n/2;
	}
}

long long int pop()
{
	long long int temp=rev[1];
	heap[1]=heap[num_heap];
	rev[1]=rev[num_heap];
	revrev[rev[1]]=1;
	rev[num_heap]=0;
	heap[num_heap]=0;
	num_heap--;
	long long int l=1;
	while((heap[2*l]<heap[l] && 2*l<=num_heap) || (heap[2*l+1]<heap[l] && 2*l+1<=num_heap))
	{
		if(heap[2*l]>heap[2*l+1] && 2*l+1<=num_heap)
		{
			swap(l,2*l+1);
			l=2*l+1;
		}
		else
		{
			swap(l,2*l);
			l=2*l;
		}
	}
	//      printf("returning %d\n",temp);
	return temp;
}

int main()
{
	long long int n,m,i,j;
	scanf("%lld%lld",&n,&m);
	while(m--)
	{
		long long int l,k,wt;
		scanf("%lld%lld%lld",&l,&k,&wt);
		head[l]=insert(head[l],k,wt);
//		head[k]=insert(head[k],l,wt);
	}
	for(i=1;i<=n;i++)
		dis[i]=1000000002;

	long long int src,dest;
	scanf("%lld%lld",&src,&dest);

	dis[src]=0;

	status[src]=2;
	long long int var=src;
	long long int temp_num=1;
	while(temp_num<=n)
	{
		node *temp=head[var];
		while(temp!=NULL)
		{
			if(status[temp->data]!=2)
			{
				if(dis[var]+temp->wt < dis[temp->data])
					dis[temp->data]=dis[var]+temp->wt;
				if(status[temp->data]==1)
					dec(temp->data);

				if(status[temp->data]==0)
				{
					insrt(temp->data);
					status[temp->data]=1;
				}
			}
			temp=temp->next;
		}
		var=pop();
		status[var]=2;
		if(var==dest)
			break;
//		status[var]=2;
		temp_num++;
	}

	if(status[dest]!=2)
		printf("NO\n");
	else
		printf("%lld\n",dis[dest]);
	return 0;
}



