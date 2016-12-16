#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define LL long long int
#define ulli unsigned long long int
#define si(n) scanf("%d",&n)
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
	int val;
	int prior;
	struct node *l,*r;
}node;
typedef node* pnode;

void split(pnode t,pnode *l,pnode *r,int key)
{
	if(!t)
		*l = *r = NULL;
	else if(t->val <= key)	//<= key will be in left subtree
		split(t->r,&(t->r),r,key) , *l = t;
	else
		split(t->l,l,&(t->l),key) , *r = t;
}
void merge(pnode *t,pnode l,pnode r)
{
	if(!l || !r)
		*t = l?l:r;
	else if(l->prior < r->prior)
		merge(&(r->l) , l ,r->l) , *t = r ;
	else
		merge(&(l->r) , l->r,r) , *t = l;
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
}

node findMin(pnode t)
{
	while(t->l)
		t = t->l;
	return *t;
}
void deleteMin(pnode *t)
{
	pnode del;
	if(!(*t)->l)
	{
		del = *t , *t = (*t)->r;
		free(del);
		return;
	}
	pnode temp = *t;
	while((temp->l->l))
		temp = temp->l;
	del = temp->l;
	temp->l = temp->l->r;
	free(del);
}

typedef struct node2{
	int val;
	struct node2* next;
}node2;
typedef node2* ptr;
void PB(ptr* head,int val)
{
	ptr p = (ptr)malloc(sizeof(node2));
	p->val = val;
	p->next = NULL;
	if(!*head)
		*head = p;
	else
		p->next = *head,*head = p;
}
void erase(ptr head)
{
	ptr temp;
	while(head)
		temp = head,head = head->next,free(temp);

}

pnode init(int val)
{
	pnode it = (pnode)malloc(sizeof(node));
	it->val = val;
	it->prior = rand();
	it->l = it->r = NULL;
	return it;
}

ptr graph[100010];
pnode treap;
int deg[100010];
int ans[100010];
int len;
int main()
{
	int n,m;
	si(n);si(m);
	int i;
	for(i=0;i<m;i++)
	{
		int u,v;
		si(u);si(v);
		PB(&graph[u],v);
		deg[v]++;
	}
	for(i=1;i<=n;i++)
		if(!deg[i])
			insert(&treap,init(i));
	while(treap)
	{
		node top = findMin(treap);
		deleteMin(&treap);
		int u = top.val;
		ans[len++] = u;
		ptr it;
		for(it = graph[u];it!=NULL;it = it->next)
		{
			deg[it->val]--;
			if(!deg[it->val])
				insert(&treap,init(it->val));
		}
	}
	for(i=0;i<len;i++)
		printf("%d%s",ans[i],i==len-1?"\n":" ");

	return 0;
}
