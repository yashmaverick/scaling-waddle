#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define LL long long int
#define ULL unsigned long long int
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')



typedef struct node{
	int val;
	struct node* next;
}node;

void insert(node** head,int elem)
{
	node* p = (node*)malloc(sizeof(node));
	p->val = elem;
	p->next = *head;
	*head = p;
	return;
}

#define N 15000

int P[N];
int A[N];
int pos[N];
node* graph[N];
int ans[2000][2000];
int visited[N];
int len;
int diff(int a,int b)
{
	int ndiff = 0;
	while(a)
	{
		if(a%10 != b%10) ndiff++;
		a = a/10;
		b = b/10;
	}
	if(ndiff == 1)
		return 1;
	return 0;
}
int queue[N];
int front,end;
int dist[N];

void bfs(int a)
{
	front = end=0;
	queue[end++] = a;
	node* it;
	int i;
	for(i=1000;i<=9999;i++)
	{
		visited[i]=0;
		dist[i]=-1;
	}
	dist[a]=0;
	while(front<end)
	{
		int u = queue[front];
		front++;
		visited[u]=1;
		for(it = graph[u];it!=NULL;it = it->next)
		{
			if(!visited[it->val])
			{
				visited[it->val] = 1;
				queue[end++] = it->val;
				dist[it->val] = dist[u] + 1;
			}
		}
	}
	for(i=0;i<len;i++)
		ans[pos[a]][i]=dist[A[i]];
}

int main()
{
	int i,j;
	P[0]=P[1]=1;
	for(i=2;i*i<N;i++)
		if(!P[i])
			for(j=i*i;j<N;j+=i)
				P[j]=1;
	for(i=1000;i<10000;i++)
		if(!P[i])
		{
			pos[i] = len;
			A[len++] = i;
		}

	for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
			if(diff(A[i],A[j]))
				insert(&graph[A[i]],A[j]),insert(&graph[A[j]],A[i]);
	for(i=0;i<len;i++)
		bfs(A[i]);
	int t;si(t);
	while(t--)
	{
		int a,b;
		si(a);si(b);
		if(a>b)
		{
			int temp = b;
			b = a;
			a = temp;
		}
		if(ans[pos[a]][pos[b]] == -1)
			printf("Impossible\n");
		else
			dout(ans[pos[a]][pos[b]]);

	}
	return 0;
}
