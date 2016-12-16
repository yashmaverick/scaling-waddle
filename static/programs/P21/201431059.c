#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	int weight;
	struct node* next;
}node;
typedef node* ptr;

ptr insert(ptr head,node elem)
{
	node* p = (ptr)malloc(sizeof(node));
	*p = elem;
	return p->next = head,p;
}
node mp(int val,int weight)
{
	node temp;
	temp.val = val;
	temp.weight = weight;
	temp.next = NULL;
	return temp;
}
ptr delete(ptr head)
{
	ptr temp = head;
	while(head)
		head = head->next,free(temp),temp = head;
	return NULL;
}

int q[2000000];
int front,end;
ptr graph[200000];
long long int dist[200000];
long long int INF = 1000000000000000000;
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u] = insert(graph[u],mp(v,w));
		//graph[v] = insert(graph[v],mp(u,w));
	}
	int s,t;
	scanf("%d %d",&s,&t);
	for(i=0;i<=n;i++)
		dist[i] = INF;
	dist[s]=0;
	front=end=0;
	q[end++] = s;
	
	
	while(front<end)
	{
		int u = q[front++];
		ptr it = graph[u];
		while(it)
		{
			if(dist[u] + (long long int)it->weight < dist[it->val])
			{
				dist[it->val] = dist[u] + (long long int)it->weight;
				q[end++] = it->val;
			}
			it = it->next;
		}
	}
	if(dist[t] == INF)
		printf("NO\n");
	else
		printf("%lld\n",dist[t]);

	return 0;
}
