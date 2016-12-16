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

void insert(node** head,int val)
{
	node* p = (node*)malloc(sizeof(node));
	p->val=val;
	p->next = *head;
	*head = p;
}

void erase(node* head)
{
	node* temp = head;
	while(head)
		head=head->next,free(temp),temp=head;
}
#define N 1000010
node* graph[N];
int ans;
int visited[N];
int dfs(int u)
{
	visited[u]=1;
	int mx = 0,smx=0;
	node* it;
	for(it=graph[u];it!=NULL;it = it->next)
		if(!visited[it->val])
		{
			int val = dfs(it->val);
			if(val >= mx)
				smx = mx,mx = val;
			else if(val>smx)
				smx = val;
		}
	ans = max(ans,mx + smx);
	return mx+1;
}

int main()
{
	int t;si(t);
	while(t--)
	{
		int n;
		si(n);
		int i;
		for(i=0;i<n;i++)
			graph[i]=NULL;
		for(i=0;i<n-1;i++)
		{
			int u,v;
			si(u);si(v);
			insert(&graph[u-1],v-1);
			insert(&graph[v-1],u-1);
		}
		for(i=0;i<n;i++)
			visited[i]=0;
		ans=0;
		dfs(0);
		dout(ans+1);	
		for(i=0;i<n;i++)
			erase(graph[i]);
	}
	return 0;
}
