#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long LL;

typedef struct list
{
	LL v;
	LL w;
	struct list *next;
} List;

typedef struct node
{
	LL vert;
	LL dist;
} Node;

List *adj[500005];
Node heap[500005];
LL hsize = 0;
LL pos[500005];
LL dis[500005];

void swap(Node *x, Node *y)
{
	Node temp = *x;
	*x = *y;
	*y = temp;
}

void init_heap(LL n)
{
	LL i;
	heap[0].dist = -6e14;
	for(i=1; i<=n; i++)
	{
		heap[i].dist = 6e14;
		heap[i].vert = i;
	}
	hsize = n+1;
}

Node getmin_heap()
{
	Node minnode = heap[1];
	pos[heap[1].vert] = 0;
	swap(&heap[1], &heap[hsize]);
	hsize--;
	pos[heap[1].vert] = 1;

	int i = 1;
	while(i < hsize/2)
	{
		if(heap[2*i].dist>heap[i].dist && heap[2*i+1].dist>heap[i].dist)
			break;
		else
		{
			if(heap[2*i].dist < heap[2*i+1].dist)
			{
				swap(&heap[2*i], &heap[i]);
				pos[heap[i].vert] = i;
				pos[heap[2*i].vert] = 2*i;
				i *= 2;
			}
			else
			{
				swap(&heap[2*i+1], &heap[i]);
				pos[heap[i].vert] = i;
				pos[heap[2*i+1].vert] = 2*i+1;
				i = 2*i+1;
			}
		}
	}

	if(hsize == 2*i+1)
	{
		if(heap[2*i].dist>heap[i].dist && heap[2*i+1].dist>heap[i].dist)
			;
		else
		{
			if(heap[2*i].dist < heap[2*i+1].dist)
			{
				swap(&heap[2*i], &heap[i]);
				pos[heap[i].vert] = i;
				pos[heap[2*i].vert] = 2*i;
				i *= 2;
			}
			else
			{
				swap(&heap[2*i+1], &heap[i]);
				pos[heap[i].vert] = i;
				pos[heap[2*i+1].vert] = 2*i+1;
				i = 2*i+1;
			}
		}
	}
	else if(hsize == 2*i)
	{
		if(heap[2*i].dist<heap[i].dist)
		{
			swap(&heap[i], &heap[2*i]);
			pos[heap[i].vert] = 1;
			pos[heap[2*i].vert] = 2*i;
		}
		else
			;
	}

	return minnode;
}

void update_heap(LL vert, LL dist)
{
	LL i = pos[vert];
	heap[i].dist = dist;

	while((i/2)>0 && heap[i].dist<heap[i/2].dist)
	{
		swap(&heap[i], &heap[i/2]);
		pos[heap[i].vert] = i;
		pos[heap[i/2].vert] = i/2;
		i /= 2;
	}
}

List *insert(LL v, LL w, List *list)
{
	List *temp = (List*)malloc(sizeof(List));
	temp->v = v;
	temp->w = w;
	temp->next = list;
	return temp;
}

void dijkstra(LL src, LL n)
{
	dis[src] = 0;
	update_heap(src, dis[src]);

	while(hsize > 0)
	{
		LL i;
		Node minnode = getmin_heap();
		LL u = minnode.vert;
		
		List *curr = adj[u];
		while(curr != NULL)
		{
			LL v = curr->v;
			if(curr->w+dis[u] < dis[v])
			{
				dis[v] = curr->w+dis[u];
				update_heap(v, dis[v]);
			}
			curr = curr->next;
		}
	}
}

int main()
{
	LL u, v, w, n, m, i, t;
	scanf("%lld%lld", &n, &m);
	
	init_heap(n);
	for(i=1; i<=n; i++)
	{
		pos[i] = i;
		dis[i] = 6e14;
	}

	for(i=0; i<m; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		adj[u] = insert(v, w, adj[u]);
	}

	LL src, dest;
	scanf("%lld%lld", &src, &dest);

	dijkstra(src, n);

	if(dis[dest] == 6e14)
		printf("NO\n");
	else
		printf("%lld\n", dis[dest]);

	return 0;
}














