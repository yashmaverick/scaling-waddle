#include<stdio.h>
#include<stdlib.h>
typedef int ll;
#define s(n) scanf("%d",&n)
#define d(n) n=(gp)malloc(1*sizeof(g))
typedef struct graph{
    ll val;
    int visited;
    struct graph *next;
}g;
ll groot;ll count;
int answ;
typedef g* gp;
gp a[1001],b[1001];
void insert(ll,ll);
void dfs(int);
void init_dfs(ll s)
{
    int i; 
    gp temp;
    for(i=0;i<=1000;i++)
    {
	if(a[i]!=NULL)
	{
	    temp=a[i];
	    while(temp!=NULL)
	    {
		temp->visited=0;
		temp=temp->next;
	    }
	}
    }
}
void init_dfs2()
{
    int i;
    gp temp;
    for(i=0;i<1001;i++)
    {
	if(b[i]!=NULL)
	{
	    temp = a[i];
	    while(temp!=NULL)
	    {
		temp->visited=0;
		temp=temp->next;
	    }
	}
    }
}
void print()
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
		printf("%d(%d)->",te->val,a[te->val]->visited);
		te=te->next;
	    }
	    printf("%d(%d)\n",te->val,te->visited);
	}
    }
}
void dfs2(ll y)
{
    gp ttt;
    ttt = b[y];
    if(ttt==NULL)
	return;
    while(ttt!=NULL)
    {
	if(b[ttt->val]->visited==0)
	{
	    b[ttt->val]->visited=1;
	    answ+=1;
	    dfs2(ttt->val);
	}
	ttt=ttt->next;
    }
    return;
}
void answer(int x)
{
    int i,ans=0,storage,flaa;
    for(i=1;i<1001;i++)
    {
	count=0;flaa=0;
	if(a[i]!=NULL)
	{
	    if(a[i]->next!=NULL)
	    {
		gp temp;
		temp=a[i];
		init_dfs(temp->val);
		dfs(temp->val);
		if(count==x)
		{
		    storage=temp->val;
		    flaa=1;
		    break;
		}
	    }
	}
    }
    answ=0;

    if(flaa==1){
    init_dfs2();
    dfs2(storage);}
    printf("%d\n",answ);
}
void init_list()
{
    int i;
    for(i=0;i<1001;i++)
    {
	a[i]=b[i]=NULL;
    }
}
int main()
{
    ll t;ll i;
    s(t);
    while(t--)
    {
	ll n;
	init_list();
	s(n);
	for(i=1;i<n+1;i++)
	{
	    ll x,a;
	    s(x);
	    while(x--)
	    {
		s(a);
		insert(a,i);
	    }
	}
	answer(n);
    }
    return 0;    
}
void insert(ll u, ll v)
{
    gp t1,t2,t3;
    d(t1);
    if(a[u]==NULL)
    {
	d(a[u]);
	a[u]->val=u;
	d(a[u]->next);
	a[u]->next->val=v;
	a[u]->next->next=NULL;
    }
    else
    {
	t1->val=v;
	t1->next=a[u]->next;
	a[u]->next=t1;
    }
    if(a[v]==NULL)
    {
	d(a[v]);
	a[v]->val = v;
	a[v]->next=NULL;
    }
    d(t2);
    if(b[v]==NULL)
    {
	d(b[v]);
	b[v]->val=v;
	d(b[v]->next);
	b[v]->next->val=u;
	b[v]->next->next=NULL;
    }
    else
    {
	t2->val=u;
	t2->next=b[v]->next;
	b[v]->next=t2;
    }
    if(b[u]==NULL)
    {
	d(b[u]);
	b[u]->val=u;
	b[u]->next=NULL;
    }
}

void dfs(ll x)
{
    gp tt;
    tt = a[x];
    if(tt==NULL)
	return;
    while(tt!=NULL)
    {
	if(a[tt->val]->visited==0)
	{
	    a[tt->val]->visited=1;
	    count+=1;
	    dfs(tt->val);
	}
	tt=tt->next;
    }
    return;
}
/*Rohan Karnawat*/
