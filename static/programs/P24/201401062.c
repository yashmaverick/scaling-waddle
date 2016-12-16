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

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

typedef struct node{
	int val,prior;
	int size;
	struct node *l,*r;
}node;
typedef node* pnode;

int sz(pnode t)
{
	return t?t->size:0;
}
void upd_sz(pnode t)
{
	if(t)
		t->size = sz(t->l) + 1 + sz(t->r);
}

void split(pnode t,pnode *l,pnode *r,int key)
{
	if(!t)
		*l = *r = NULL;
	else if(t->val <= key)	//<= key will be in left subtree
		split(t->r,&(t->r),r,key) , *l = t;
	else
		split(t->l,l,&(t->l),key) , *r = t;
	upd_sz(t);
}
void merge(pnode *t,pnode l,pnode r)
{
	if(!l || !r)
		*t = l?l:r;
	else if(l->prior < r->prior)
		merge(&(r->l) , l ,r->l) , *t = r ;
	else
		merge(&(l->r) , l->r,r) , *t = l;
	upd_sz(*t);
}

void insert(pnode *t,pnode it)
{
	if(!(*t))
		*t = it;
	else if((*t)->prior < it->prior)
		split(*t , &(it->l) , &(it->r) , it->val) , *t = it;
	else if((*t)->val >= it->val)
		insert(&((*t)->l) , it);
	else
		insert(&((*t)->r) , it);
	upd_sz(*t);
}

int find(pnode t,int key)
{
	if(!t)  return 0;
	else if(t->val < key)
		return find(t->r,key);
	else if(t->val > key)
		return find(t->l,key);
	else
		return 1;
}


int kth(pnode t,int k)
{
	if(!t)
		return -1;
	if(sz(t->l) == k-1)
		return t->val;
	else if(sz(t->l)+1 < k)
		return kth(t->r,k - sz(t->l)-1);
	else if(sz(t->l) >= k)
		return kth(t->l,k);
}

int count(pnode t,int x)
{
	if(!t) return 0;
	else if(t->val == x)
		return sz(t->l);
	else if(t->val < x)
		return sz(t->l) + 1 + count(t->r,x);
	else if(t->val > x) 
		return count(t->l,x);
}

pnode Treap;

int main()
{
	char in[100];
	while(1)
	{
		scanf("%s",in);
		if(!strcmp(in,"Quit")) break;
		int val;
		din(val);
		if(!strcmp(in,"SetHealthy"))
		{
			pnode it = (pnode)malloc(sizeof(node));
			it->val = val;
			it->prior = rand();
			it->size = 1;
			it->l = it->r = NULL;
			insert(&Treap , it);
		}
		else if(!strcmp(in,"CheckHealthy"))
			printf("%s\n",find(Treap,val)?"YES":"NO");
		else if(!strcmp(in,"Healthy"))
		{
			int ret = kth(Treap,val);
			if(ret==-1)
				printf("NONE\n");
			else
				dout(ret);
		}
		else if(!strcmp(in,"RottenBefore"))
			dout(count(Treap,val));

	}		
	return 0;
}
