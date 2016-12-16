#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct ll
{
	int node;
	struct ll *next;
}ll;
int heap[1000000];
int *in,n;
ll **g;
int heapcount;
ll* create(ll *g, int v)
{
    ll *h = (ll *)malloc(sizeof(ll));
    h->node=v;
    h->next=g;
    return h;
}
void inheap(int value)
{
	heapcount++;
	heap[heapcount] = value;
	int i = heapcount;
	while(heap[i/2]>value)
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=value;
}
int pop()
{
	int ans = heap[1],temp;
    temp = heap[heapcount--];
    int i,j;
    for(i=1;2*i<=heapcount;i=j)
    {
        j=2*i;
        if(j!=heapcount && heap[j+1] < heap[j])
            j++;
        if(temp > heap[j])
            heap[i] = heap[j];
        else
            break;
    }
    heap[i] = temp;
    return ans;
}
int main()
{
	heapcount = 0;
	heap[0] = INT_MIN;
	int m,i;
	scanf("%d %d",&n,&m);
	g = (ll **)malloc(sizeof(ll*)*(n+1));
	in = (int *)malloc(sizeof(int)*(n+1));
	int arr[n];
	int k=0;
	for(i=1;i<=n;i++)
	{
		g[i]=NULL;
		in[i]=0;
	}
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a]=create(g[a],b);
		in[b]++;
	}
	for(i=1;i<=n;i++)
		if(in[i]==0)
			inheap(i);
	while(heapcount!=0)
	{
		int node = pop();
		arr[k++]=node;
		ll *head = g[node];
		while(head!=NULL)
		{
			if(in[head->node]!=0)
			{
				in[head->node]--;
				if(in[head->node]==0)
					inheap(head->node);
			}
			head = head->next;
		}
	}
	for(i=0;i<k-1;i++)
		printf("%d ",arr[i]);
	printf("%d\n",arr[i]);
	return 0;
}