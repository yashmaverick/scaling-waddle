#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 10000000000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')


#define N 100010

typedef struct node{
	int index;
	lli weight;
	struct node* next;
}node;

void push_back(node ** head,int index,int weight)
{
	node* p = (node*)malloc(sizeof(node));
	p->index = index;
	p->weight = weight;
	p->next = NULL;
	if(*head==NULL)
	{
		(*head = p);
		return;
	}
	node* start = *head;
	while(start->next!=NULL)
		start = start->next;
	start->next = p;
}

node heap[N];
int pos;

void insert(node elem)
{
	pos++;
	heap[pos]=elem;
	int cpos = pos;
	//shuffle up
	while(heap[cpos].weight < heap[cpos/2].weight)
	{
		node temp = heap[cpos];
		heap[cpos] = heap[cpos/2];
		heap[cpos/2] = temp;
	}
}
node top()
{
	return heap[1];
}
void deleteMin()
{
	//swap top with leaf and delete leaf
	node temp = heap[pos];
	heap[pos] = heap[1];
	heap[1] = temp;
	pos--;
	//now shuffle down the top to make it reach to the appropriate place
	int cpos = 1;
	while(cpos < pos )
	{
		if(cpos*2 >pos)
			break;
		int mn;
		if(cpos*2 + 1>pos)
			mn = cpos*2;
		else
			mn = (heap[cpos*2].weight > heap[cpos*2 + 1].weight ? cpos*2 + 1 : cpos*2);
		if(heap[cpos].weight > heap[mn].weight)
		{
			temp = heap[cpos];
			heap[cpos] = heap[mn];
			heap[mn] = temp;
			cpos = mn;
		}
		else
			break;
	}
	//shuffle down ends	
}
int isEmpty()
{
	if(pos == 0)
		return 1;
	else 
		return 0;
}

node mp(int u,lli weight)
{
	node temp;
	temp.index = u;
	temp.weight = weight;
	return temp;
}
node* graph[N];
lli dist[N];
int visited[N];
void reset(int n)
{
	pos = 0;
	int i;
	for(i=0;i<=n;i++)
	{
		/*node* head = graph[i];
		while(head!=NULL)
		{
			node* temp = head;
			head = head->next;
			free(temp);
		}*/
		graph[i] = NULL;
		visited[i]=0;
	}
}
int main()
{
	int t,i;
		int n,m;
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			push_back(&graph[u],v,w);
		}
		int s,d;
		scanf("%d %d",&s,&d);
		for(i=1;i<=n;i++)
			dist[i] = INF;
		dist[s]=0;
		insert(mp(s,0));
		while(!isEmpty())
		{
	//		printf("%d ",pos);
			node Top = top();
			int u = Top.index;
			deleteMin();
			if(visited[u]) continue;
			visited[u]=1;
			node* it;
			for(it = graph[u];it!=NULL;it = it->next)
			{
				int v = it->index;
				lli weight = it->weight;
				if(dist[u] + weight < dist[v])
				{
					dist[v] = dist[u] + weight;
					insert(mp(v,dist[v]));
				}
			}
		}
		if(dist[d] == INF)
			printf("NO\n");
		else
			lldout(dist[d]);
	return 0;
}
