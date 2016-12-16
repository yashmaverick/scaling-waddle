#include<stdio.h>
#include<stdlib.h>
#define gi(x) scanf("%lld",&x);
typedef long long int ll;
typedef struct node{
	ll data;
	struct node * next;
}node;
typedef struct NODE{
	ll vertex;
}NODE;
ll visited[5000005]={0};
ll topo_arr[5000005];
ll size[5000005],rev[5000005];
ll heapsize;
NODE heap[5000005];
void insert(NODE element)
{
	heapsize++;
	heap[heapsize]=element;
	ll now=heapsize;
	while(heap[now/2].vertex > element.vertex)
	{
		heap[now]=heap[now/2];
		now /=2;
	}
	heap[now]=element;
}
NODE delete()
{
	NODE min,last;
	ll child,now;
	min=heap[1];
	last=heap[heapsize--];
	for(now=1;now*2<=heapsize;now=child)
	{
		child=now*2;
		if(child !=heapsize && heap[child+1].vertex < heap[child].vertex)
		{
			child++;
		}
		if(last.vertex > heap[child].vertex)
		{
			heap[now]=heap[child];
		}
		else
			break;
	}
	heap[now]=last;
	return min;
}
int main()
{
	ll n,m,i,j,g,u,v,a,b;
	gi(n);
	gi(m);
	node *arr[n+1],*l,*p;
	for(i=1;i<=n;i++)
	{
			arr[i]=(node *)malloc(sizeof(node));
			l=arr[i];
			l->data=i;
			l->next=NULL;
			visited[i]=0;
			size[i]=0;
			rev[i]=0;
	}
	for(g=0;g<m;g++)
	{
			long long int a,b;
			gi(a);
			gi(b);
			size[b]=size[b]+1;
			rev[a]=rev[a]+1;
			//l=(node *)malloc(sizeof(node));
			l=arr[a];
			if(l->next==NULL)
			{
				l->next=(node *)malloc(sizeof(node));
				l=l->next;
				l->data=b;
				l->next=NULL;
			}
			else
			{
				l=arr[a];
				p=(node *)malloc(sizeof(node));
				p->data=b;
				p->next=l->next;
				l->next=p;				
			}
	}
	for(i=1;i<=n;i++)
	{
		NODE temp;
		if(size[i]==0)
		{
			temp.vertex=i;
			insert(temp);
			visited[i]=1;
		}
	}
	ll hello=1;
	ll k,h;
	while(heapsize)
	{
		NODE min=delete();
		ll k=min.vertex;
		topo_arr[hello++]=k;
		l=arr[k];
		for(h=1;h<=rev[k]+1;h++)
		{
			size[l->data]=size[l->data]-1;
			if(size[l->data]==0)
			{
				NODE help;
				help.vertex=l->data;
				visited[l->data]=1;
				insert(help);
			}
			l=l->next;
		}
	}
	if(topo_arr[hello-1]==0)
		printf("Sandro fails.\n");
	else
	{
	for(i=1;i<hello-1;i++)
	{
		printf("%lld ",topo_arr[i]);
	}
	printf("%lld\n",topo_arr[hello-1]);
	}
	return 0;
}