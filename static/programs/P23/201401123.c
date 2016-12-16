#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
#define s(n) scanf("%lld",&n)
#define d(n) n=(gp)malloc(1*sizeof(g))
#define f(i,n) for(i=0;i<n;i++)
typedef struct graph{
    ll val;
    ll weight;
    struct graph *next;
}g;
typedef g* gp;
gp a[1000001];
ll heap[1000001];
ll pre[1000001];
ll ans[100001];
ll size;
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
    else
    {
	t1->val=v;
	t1->next=a[u]->next;
	a[u]->next=t1;
    }
    if(a[v]==NULL)
    {
	d(a[v]);
	a[v]->val=v;
	a[v]->next=NULL;
    }
}

void insertheap(ll x,ll j)
{
    ll t;
    heap[j]=x;
    if(j>1)
    {
	while(heap[j]<heap[j/2] && j>1)
	{
	    t=heap[j];
	    heap[j]=heap[j/2];
	    heap[j/2]=t;
	    j=j/2;
	}
    }
}

void deleteMin()
{
    ll t,temp;
    t=heap[1];
    heap[1]=heap[size];
    heap[size]=t;
    size-=1;
    ll k=1;
    ll j;
    while(2*k<=size && (heap[k]>heap[2*k] || heap[k]>heap[2*k+1]))
    {
	j=2*k;
	if(2*k!=size && heap[2*k+1]<heap[2*k])
	    j++;
	if(heap[k]>heap[j])
	{
	    t=heap[k];heap[k]=heap[j];heap[j]=t;
	}
	k=j;
    }
}
int main()
{
    ll n,m;
    s(n);
    s(m);
    ll k;
    f(k,100001){pre[k]=0;}
    ll i,I,J;
    f(i,m){
	s(I);
	s(J);
	insert(I,J);
	pre[J]+=1;
    }
    size=0;
    for(i=1;i<=n;i++){
	if(pre[i]==0)
	{
	    size++;
	    insertheap(i,size);
	}}
    ll groot;
    ll pp=0;
    //printf("pre[1]=%lld\n",pre[1]);
    while(size!=0)
    {
        //printf("pre[1]=%lld\n",pre[1]);
	groot=heap[1];
	//printf("%lld ",groot);
	ans[pp++]=groot;

	deleteMin();
	gp t;
	t = a[groot];
	if(t!=NULL)//&& t->next)
	{
	    t=t->next;
	    while(t!=NULL)
	    {
		//printf("$\n");
	        //printf("pre[1]=%lld\n",pre[1]);
		if(pre[t->val]!=0)
		    pre[t->val]=pre[t->val]-1;
      		//printf("pre[1]=%lld and here t->val =%lld\n",pre[1],t->val);
		if(pre[t->val]==0)
		{
		  //  printf("*\n");
		    size++;
		    insertheap(t->val,size);
		}
		t=t->next;
	    }
	}
    }
    ll p;
    for(p=0;p<pp-1;p++)
	printf("%lld ",ans[p]);
    printf("%lld",ans[p]);
    putchar('\n');
    return 0;
}

