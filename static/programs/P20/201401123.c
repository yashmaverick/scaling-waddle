#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
typedef long long int ll;
#define s(n) scanf("%lld",&n)
#define d(n) n=(gp)malloc(1*sizeof(g))
#define f(i,n) for(i=0;i<n;i++)
typedef struct graph{
    ll val;
    ll depth,visited;
    ll parent;
    struct graph *next;
}g;
ll groot;ll n;
typedef g* gp;
gp a[1000001];
ll maxdepth,farthest;
void insert(ll,ll);
/* in  a tree from A to B there can be only ONE path*/
void init_list()
{
    int i;
    for(i=0;i<1000001;i++)
    {
	a[i]=NULL;
    }
}

void init_dfs()
{
    int i; 
    gp temp;
    for(i=0;i<=1000000;i++)
    {
	if(a[i]!=NULL)
	{
	    temp=a[i];
	    while(temp!=NULL)
	    {
		temp->visited=0;
		temp->depth=0;
		temp->parent=(-1);
		temp=temp->next;
	    }
	}
    }
    //maxdepth=0;
    return;
}

void dfs(ll,ll);
/*void print()
{
    int i;
    gp te;
    for(i=1;i<1001;i++)
    {
	if(a[i]!=NULL)
	{
	    te = a[i];
	    while(te->next!=NULL)
	    {
		printf("%lld(%lld)->",te->val,a[te->val]->visited);
		te=te->next;
	    }
	    printf("%lld(%lld)\n",te->val,te->visited);
	}
    }
}*/
ll answer;
void dfs2(ll current, ll pant)
{
    gp ttt;
    ttt = a[current];
    if(ttt==NULL)
	return;
    while(ttt!=NULL)
    {
	if(a[ttt->val]->visited==0)
	{
	    a[ttt->val]->visited=1;
	    a[ttt->val]->parent=pant;
	    if(a[ttt->val]->parent!=-1)
		a[ttt->val]->depth = a[pant]->depth+1;
	    if(a[ttt->val]->depth > maxdepth)
	    {
		maxdepth = a[ttt->val]->depth;
	    }
	    dfs(ttt->val,ttt->val);
	}
	ttt=ttt->next;
    }
    return;
}

int main()
{
    ll t;
    s(t);
    while(t--)
    {
	ll u,v;
	s(n);
	//a=(gp)malloc(n*sizeof(g));
	// gp* = g**
	init_list();
	ll edge=n-1;
	ll i;
	for(i=0;i<edge;i++)
	{
	    s(u);s(v);
	    if(i==0)
	    groot=u;//assuming this to be root
	    insert(u,v);
	}
	//print();
	//printf("GROOT= %lld\n",groot);
	init_dfs();
	maxdepth = 0;
	dfs(groot,-1);
	//printf("%lld %lld\n",maxdepth,farthest);
	//answer=0;
	maxdepth = 0;
	init_dfs();
	dfs2(farthest,-1);
	printf("%lld\n",maxdepth+1);
    }
    return 0;
}

void dfs(ll current, ll pant)
{
    gp tt;
    tt = a[current];
    if(tt==NULL)
	return;
    while(tt!=NULL)
    {
	if(a[tt->val]->visited==0)
	{
	    a[tt->val]->visited=1;
	    a[tt->val]->parent=pant;
	    if(a[tt->val]->parent!=-1)
		a[tt->val]->depth = a[pant]->depth + 1;
	    if(a[tt->val]->depth > maxdepth)
	    {
		maxdepth = a[tt->val]->depth;
		farthest = tt->val;
	    }
	    dfs(tt->val,tt->val);
	}
	tt=tt->next;
    }
    return;
}

void insert(ll u, ll v)
{
    gp t1,t2,t3;
    d(t1);d(t2);
    if(a[u]==NULL)
    {
	d(a[u]);
	a[u]->val=u;
	d(a[u]->next);
	a[u]->next->val=v;
	a[u]->next->next=NULL;
    }
    else{
	t1->val=v;
	t1->next=a[u]->next;
	a[u]->next=t1;
    }
    if(a[v]==NULL)
    {
	d(a[v]);
	a[v]->val=v;
	d(a[v]->next);
	a[v]->next->val=u;
	a[v]->next->next=NULL;
    }
    else{
	t2->val=u;
	t2->next=a[v]->next;
	a[v]->next=t2;
    }
}
/*rohan karnawat*/
