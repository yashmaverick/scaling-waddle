#include<stdio.h>
#include<stdlib.h>
#define infinite 9999999999
#define gi(x) scanf("%lld",&x);
typedef long long int ll;
typedef struct heapnode{
	ll vertex,distance;
}heapnode;
typedef struct node{
	ll data;
	ll weight;
	struct node * next;
}node;
heapnode heap[5000005];
ll heapsize=0;
ll visited[500005];
ll dist[500005];
//ll size[500005];
ll rev[500005];
void insert(heapnode num)
{
	heapsize++;
	heap[heapsize]=num;
	ll present = heapsize;
	while(heap[present/2].distance > num.distance)
	{
		heap[present]=heap[present/2];
		present/=2;
	}
	heap[present]=num;
}
heapnode delete()
{
	heapnode min,last;
	ll present,child;
	min=heap[1];
	last=heap[heapsize--];
	for( present=1 ; (present*2) <= heapsize;present=child)
	{
		child=present*2;
		if(child!=heapsize && heap[child+1].distance < heap[child].distance)
		{
			child++;
		}
		if(last.distance > heap[child].distance)
		{
			heap[present]=heap[child];
		}
		else
			break;
	}
	heap[present]=last;
	return min;
}
int main()
{
	ll test;
	ll i,j,n,m,u,v,w;
	gi(n);
	gi(m);
	node *arr[n+1],*l,*p;
	for(i=1;i<=n;i++)
	{
		arr[i]=(node *)malloc(sizeof(node));
		l=arr[i];
		l->data=i;
		l->weight=0;
		l->next=NULL;
		visited[i]=0;
		//size[i]=0;
		rev[i]=1;
	}

	ll g,a,b;
	for(g=0;g<m;g++)
	{
		gi(a);
		gi(b);
		gi(w);
		//size[b]=size[b]+1;
		rev[a]=rev[a]+1;
		//add(a,b,w);
		l=arr[a];
		if(l->next==NULL)
		{
			l->next=(node *)malloc(sizeof(node));
			l=l->next;
			l->data=b;
			l->weight=w;
			l->next=NULL;
		}
		else
		{
			l=arr[a];
			p=(node *)malloc(sizeof(node));
			p->data=b;
			p->weight=w;
			p->next=NULL;
			p->next=l->next;
			l->next=p;
		}
	}
	for(i=1;i<=n;i++)
	{
		dist[i]=infinite;
	}
	ll source,desti;
	gi(source);
	gi(desti);
	heapnode temp;
	for(i=1;i<=n;i++)
	{
		if(i==source)
		{
			temp.vertex=i;
			temp.distance=0;
			dist[i]=0;
			insert(temp);
		}
		else
		{
			temp.distance=infinite;
			dist[i]=infinite;
			temp.vertex=i;
			//insert(temp);
		}
	}
	while(heapsize)
	{
		heapnode min = delete();
		ll present = min.vertex;
		if(visited[present])
		{
			continue;
		}
		visited[present]=1;
		node *lol;
		lol=arr[present];
		for(i=1;i<=rev[present];i++)
		{
			ll too=lol->data;
			ll hh=lol->weight;
			if(dist[too] > ( dist[present] + hh))
			{
				dist[too]=dist[present] + hh;
				temp.vertex=too;
				temp.distance=dist [too];
				insert(temp);
			}
			lol=lol->next;
		}
	}
	if(dist[desti]!=infinite)
	printf("%lld\n",dist[desti]);
	else
	printf("NO\n");
return 0;
}