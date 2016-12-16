#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	long long int data;
	long long int wt;
	struct node *next;
}node;

node *head[100005];
long long int num_heap=0;

node *insert(node *root,long long int k,long long int w)
{
	node *temp=malloc(sizeof(node));
	temp->data=k;
	temp->wt=w;
	temp->next=root;
	return temp;
}

long long int heap[100005],rev[100005];
long long int status[100005],weight[100005];

void swap(long long int a,long long int b)
{
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
	heap[num_heap]=weight[n];
	rev[num_heap]=n;
	long long int l=num_heap;
	while(heap[l/2]>heap[l] && l>1)
	{
		swap(l,l/2);
		l=l/2;
	}
}


void dec(long long int n)
{
	long long int i;
	for(i=1;i<=num_heap;i++)
	{
		if(rev[i]==n)
		{
			n=i;
			break;
		}
	}
	heap[n]=weight[rev[n]];

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
//	printf("returning %d\n",temp);
	return temp;
}

void wght()
{
	printf("wt ");
	long long int i;
	for(i=1;i<10;i++)
		printf("%lld ",weight[i]);
	printf("\n");
}

void hp()
{
	printf("hp ");
	long long int i;
	for(i=1;i<10;i++)
		printf("%lld ",heap[i]);
	printf("\n");
}

void rv()
{
	printf("re ");
	long long int i;
	for(i=1;i<10;i++)
		printf("%lld ",rev[i]);
	printf("\n");
}

int main()
{
	long long int n,m,i,j;
	scanf("%lld%lld",&n,&m);
	while(m--)
	{
		long long int l,k,w;
		scanf("%lld%lld%lld",&l,&k,&w);
		head[l]=insert(head[l],k,w);
		head[k]=insert(head[k],l,w);
	}

//	wght();

	for(i=1;i<100005;i++)
		weight[i]=1001;
//	wght();
	long long int var=1;

	long long int temp_num=1;
	status[1]=2;
	weight[1]=0;
	while(temp_num<=n)
	{
		node *temp=head[var];
		while(temp!=NULL)
		{
			if(status[temp->data]!=2)
			{
				if(temp->wt < weight[temp->data])
				{
					weight[temp->data]=temp->wt;
					if(status[temp->data]==1)
					{
						dec(temp->data);

					}
					if(status[temp->data]==0)
					{
						insrt(temp->data);
						status[temp->data]=1;
					}
				}
			}
			temp=temp->next;
		}
	//	wght();
	//	hp();
	//	rv();
		
		var=pop();    //pop,dec,ins
		status[var]=2;
		temp_num++;
	}
	long long int sum=0;
	int flag=1;
	for(i=1;i<=n;i++)
	{
		if(weight[i]==1001)
			flag=0;
	}
	for(i=1;i<=n;i++)
		sum=sum+weight[i];
	if(flag==0)
		printf("-1\n");
	else
		printf("%lld\n",sum);
	return 0;
}
