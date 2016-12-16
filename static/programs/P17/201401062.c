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

#define N 100010
#define LOGN 20
int inorder[N];
int preorder[N];
int pos[N];
int level[N];
int DP[N][LOGN];
typedef struct node{
	int val;
	struct node *l,*r;
}node;



// O(N) :)
node* build(int l,int r,int l2,int r2)
{
	if(l>=r)
		return NULL;
	node* t = (node*)malloc(sizeof(node));
	t->val = preorder[l];
	t->l = t->r = NULL;
	int cnt = 0;
	cnt = pos[preorder[l]] - l2;
	t->l = build(l+1,l+cnt+1,l2,l2+cnt);
	t->r = build(l+cnt+1,r,l2+cnt+1,r2);
	return t;
}

void print(node* head)
{
	if(!head)return;
	print(head->l);
	printf("%d ",head->val);
	print(head->r);
}

void dfs(node* head)
{
	if(!head)
		return;

	if(head->l) level[head->l->val] = level[head->val] + 1;
	if(head->r) level[head->r->val] = level[head->val] + 1;
	if(head->l) DP[head->l->val][0] = head->val;
	if(head->r) DP[head->r->val][0] = head->val;
	dfs(head->l);
	dfs(head->r);

}

int lca(int a,int b)
{
	if(level[a]>level[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int d = level[b] - level[a];
	int i;
	for(i=0;(1<<i)<=d;i++)
		if(d & (1<<i))
			b = DP[b][i];
	if(a == b)
		return a;

	for(i = 0;DP[a][i]!=DP[b][i];i++);
	
	for(i = i-1;i>=0;i--)
		if(DP[a][i]!=DP[b][i])
		{
			a = DP[a][i];
			b = DP[b][i];
		}
	return DP[a][0];
}

int main()
{
	int n;
	si(n);
	int i,j;
	for(i=0;i<n;i++)
		si(preorder[i]);
	for(i=0;i<n;i++)
	{
		si(inorder[i]);
		pos[inorder[i]] = i;
	}
	node* tree = build(0,n,0,n);
	level[tree->val]=0;
	DP[tree->val][0]=tree->val;
	dfs(tree);
	for(j=1;j<LOGN;j++)
		for(i=0;i<=n;i++)
			DP[i][j] = DP[DP[i][j-1]][j-1];
	int q;
	si(q);
	while(q--)
	{
		int a,b;
		si(a);si(b);
		dout(lca(a,b));
	}
	return 0;
}
