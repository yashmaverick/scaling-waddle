#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct h{
	long long weight,node;
}h;
typedef struct adj{
	long long val;
	struct adj *link;
	long long w;
}adj;
h heap[100006];
long long a[100006],key[100006];
long long front=0;
adj *list[100006];
h deleteheap()
{
	h temp,delel;
	long long newcrap;
	//printf("deled el is %d\n",heap[1]);
	delel=heap[1];
	temp=heap[front];
	front--;
	//	key[delel.node]=0;
	long long crap=1;
	for(crap=1;2*crap<=front;crap=newcrap)
	{
		newcrap=crap*2;
		if(newcrap!=front&&heap[newcrap+1].weight<heap[newcrap].weight)
			newcrap++;
		if(temp.weight> heap[newcrap].weight)
		{
			long long g;
			h te;
			g=key[heap[crap].node];
			key[heap[crap].node]=key[heap[newcrap].node];
			key[heap[newcrap].node]=g;
			te=heap[crap];
			heap[crap]=heap[newcrap];
			heap[newcrap]=te;
		}
		else
			break;
	}
	long long g;
	g=key[heap[crap].node];
	key[heap[crap].node]=key[temp.node];
	key[temp.node]=g;
	heap[crap]=temp;
	key[delel.node]=0;

	//printf("about to return\n");
	return delel;
}
void heapinsert(long long x,long long y)
{
	front++;
	key[x]=front;
	heap[front].node=x;
	heap[front].weight=y;
	long long t=front;
	while(heap[t/2].weight>heap[t].weight&&(t/2)!=0)
	{
		h temp;
		long long g;
		g=key[heap[t/2].node];
		temp=heap[t/2];
		key[heap[t/2].node]=key[heap[t].node];
		heap[t/2]=heap[t];
		key[heap[t].node]=g;
		heap[t]=temp;
		t=t/2;

	}
}
void heapupdate(long long x,long long y)
{
	long long t=key[x];
	heap[t].weight=y;
	while(heap[t/2].weight>heap[t].weight&&(t/2)!=0)
	{
		h temp;
		long long g;
		g=key[heap[t/2].node];
		temp=heap[t/2];
		key[heap[t/2].node]=key[heap[t].node];
		heap[t/2]=heap[t];
		key[heap[t].node]=g;
		heap[t]=temp;
		t=t/2;

	}

}
int main()
{
	long long i,m,n,v1,v2,we,s,t;
	h el;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		list[i]=NULL;
		a[i]=INT_MAX;
		key[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&v1,&v2,&we);
		adj *temp=(adj*)malloc(sizeof(adj));
		temp->val=v2;
		temp->w=we;
		temp->link=list[v1];
		list[v1]=temp;

	}
	scanf("%lld %lld",&s,&t);
	heapinsert(s,0);
	a[s]=0;
	while(front!=0)
	{
		el=deleteheap();
		adj*temp=list[el.node];

		while(temp!=NULL)
		{
			//printf("came here\n");
			if(key[temp->val]==0)
			{

				if(a[el.node]+temp->w<a[temp->val])
				{
					a[temp->val]=a[el.node]+temp->w;
					heapinsert(temp->val,a[temp->val]);
				}

			}
			else
			{
				if(a[el.node]+temp->w<a[temp->val])
				{
					a[temp->val]=a[el.node]+temp->w;
					heapupdate(temp->val,a[temp->val]);
				}
			}

			temp=temp->link;	

		}
		//	printf("%lld\n",a[t]);
	}
	if(a[t]==INT_MAX)
		printf("NO\n");
	else
		printf("%lld\n",a[t]);
	/*	scanf("%lld",&n);
		i=n;
		while(i--)
		{
		scanf("%lld %lld",&v1,&v2);
		heapinsert(v1,v2);
		}
		for(i=1;i<=n;i++)
		printf("%lld ",key[i]);
		printf("\n");
		while(front!=0)
		{
		el=deleteheap();
		printf("%lld %lld\n",el.node,el.weight);
		for(i=1;i<=n;i++)
		printf("%lld ",key[i]);
		printf("\n");

		}
	 */
	return 0;
}
