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
	p->val = val;
	p->next = NULL;
	if(!*head)
		*head = p;
	else
		p->next = *head,*head = p;
}
void erase(node* head)
{
	node* temp;
	while(head)
		temp = head,head = head->next,free(temp);

}

#define N 10010
node* graph[N];
node* rgraph[N];
int indeg[N];
int size[N];
int compNo[N];
int visited[N];
int currcmp;
int order[N];
int ordlen;

void dfs1(int u)
{
	visited[u]=1;
	node* it;
	for(it = graph[u];it!=NULL;it = it->next)
		if(!visited[it->val])
			dfs1(it->val);
	order[ordlen++] = u;
}

void dfs2(int u)
{
	visited[u]=1;
	compNo[u] = currcmp;
	size[currcmp]++;
	node* it;
	for(it = rgraph[u];it!=NULL;it = it->next)
		if(!visited[it->val])
			dfs2(it->val);	
}

int main()
{
	int t;si(t);
	while(t--)
	{
		int n;
		si(n);
		int i,j;
		for(i=0;i<n;i++)
			rgraph[i]=graph[i]=NULL;
		for(i=0;i<n;i++)
		{
			int m;
			si(m);
			for(j=0;j<m;j++)
			{
				int v;
				si(v);
				insert(&graph[v-1],i);
				insert(&rgraph[i],v-1);
			}
		}
		for(i=0;i<n;i++)
			visited[i]=0;
		ordlen=0;
		for(i=0;i<n;i++)
			if(!visited[i])
				dfs1(i);
		
		for( i=0;i<n;i++)
			visited[i]=size[i] = 0;
		currcmp = 0;
		for(i=0;i<n;i++)
		{
			int w = order[n - i -1];
			if(!visited[w])
			{
				dfs2(w);
				currcmp++;
			}
		}

		node* it;
		for(i=0;i<n;i++)
			for(it = graph[i];it!=NULL;it=it->next)
				if(compNo[i]!=compNo[it->val])
					indeg[compNo[it->val]]++;
		int cnt=0,index=-1;
		for(i=0;i<currcmp;i++)
			if(indeg[i]==0)
				cnt++,index = i;
		if(cnt == 1)
			dout(size[index]);
		else
			dout(0);

		for(i=0;i<n;i++)
			erase(graph[i]),erase(rgraph[i]);
	}
	return 0;
}
