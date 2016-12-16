/*clear ---------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
typedef long long int ll;
#define s(n) scanf("%lld",&n)
#define d(n) n=(gp)malloc(1*sizeof(g))
#define f(i,n) for(i=0;i<n;i++)
typedef struct graph{
    ll val;
    ll weight;
    struct graph *next;
}g;
/*typedef struct minheap{
    ll dist;
    ll v;
}m;*/
typedef g* gp;
//typedef m* mp;
gp a[1000001];
ll heap[2][1000001];
ll dist[1000001];
ll visited[1000001];
ll indxe[1000001];
ll groot;
ll size;
void print();
void insert(ll u, ll v, ll w)
{
    gp t1,t2,t3;
    d(t1);d(t2);
    if(a[u]==NULL)
    {
	d(a[u]);
	a[u]->val=u;
	d(a[u]->next);
	a[u]->next->val=v;
	a[u]->next->weight=w;
	a[u]->next->next=NULL;
    }
    else
    {
	t1->val=v;
	t1->weight=w;
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
/*clear---------------------------------------------------------------------------------------*/
void init_dijkstra()
{
    ll i;
    gp temp;
    for(i=0;i<=1000000;i++)
    {
	visited[i]=dist[i]=indxe[i]=-1;
    }
}
//heapify here: (shuffleUP)
void shuffleUp(ll iter,ll no)
{
    ll t1,t2,t3;
    ll j = iter;
    if(j>1)
    {
	while(heap[0][j]<heap[0][j/2] && j>1)
	{
	    t1=heap[0][j];t2=heap[1][j];
	    heap[0][j]=heap[0][j/2];heap[1][j]=heap[1][j/2];
	    heap[0][j/2]=t1;heap[1][j/2]=t2;
	    t3=indxe[no];
	    //no=heap[1][j/2];
	    indxe[no]=indxe[heap[1][j]];
	    indxe[heap[1][j]]=t3;
	    j/=2;
	}
    }
}
int fl;
void insertheap(ll w,ll no, ll j)
{
    if(indxe[no]!=-1)
    {
	size--;
	ll g,h;
	g=w+heap[0][1];
	//old weight heap[0][h]
	h=heap[0][indxe[no]];
	if(g<h)
	{
	    heap[0][indxe[no]] = g;
	    shuffleUp(indxe[no],no);
	}
	else
	    return;
    }
    else
    {
	ll t1,t2,t3;
	if(fl==0)
	    heap[0][j]=w;
	else
	    heap[0][j]=heap[0][1]+w;
	heap[1][j]=no;
	indxe[no]=j;
	if(j>1)
	{
	    while(heap[0][j]<heap[0][j/2] && j>1)
	    {
		t1=heap[0][j];t2=heap[1][j];
		heap[0][j]=heap[0][j/2];heap[1][j]=heap[1][j/2];
		heap[0][j/2]=t1;heap[1][j/2]=t2;
		t3=indxe[no];
		indxe[no]=indxe[heap[1][j]];
		indxe[heap[1][j]]=t3;
		j/=2;
	    }
	}
    }
}
ll minw,minv;
void deleteMin()
{
    minw = heap[0][1];
    minv = heap[1][1];
    visited[heap[1][1]]=1;
    ll t1,t2,t,T,t3,T3;
    //swap indxe of heap1,1 and heap 1,size
    t3=indxe[heap[1][1]];
    indxe[heap[1][1]]=indxe[heap[1][size]];
    indxe[heap[1][size]]=t3;

    t1=heap[0][1];t2=heap[1][1];
    heap[0][1]=heap[0][size]; heap[1][1]=heap[1][size];
    heap[0][size]=t1; heap[1][size]=t2;
    size-=1;/*size decreases by 1 here*/
    ll k=1;
    ll j;
    while(2*k<=size && (heap[0][k]>heap[0][2*k] || heap[0][k]>heap[0][2*k + 1]))
    {
	j=2*k;
	if(2*k!=size && heap[0][2*k+1]<heap[0][2*k])
	    j++;
	if(heap[0][k]>heap[0][j])
	{
	    T3=indxe[heap[1][k]];indxe[heap[1][k]]=indxe[heap[1][j]];indxe[heap[1][j]]=T3;
	    t=heap[0][k];heap[0][k]=heap[0][j];heap[0][j]=t;
	    T=heap[1][k];heap[1][k]=heap[1][j];heap[1][j]=T;
	}
	k=j;
    }
}
void dijkstra(ll p,ll q)
{
    if(a[p]==NULL || a[q]==NULL)
    {
	printf("NO\n");
	return;
    }
    gp temp;
    temp = a[p];
    fl = 0;
    size++;
    insertheap(0,temp->val,size);
    temp=temp->next;
    fl=1;
    while(size!=0)
    {
	while(temp!=NULL)
	{
	    if(visited[temp->val]!=1)
	    {
	    size++;
		insertheap(temp->weight,temp->val,size);
	    }
	    temp=temp->next;
	}
	deleteMin();
	dist[minv]=minw;
	if(dist[q]!=-1)
	{
	    printf("%lld\n",dist[q]);
	    return;
	}
	//visited[minv]=1;
	if(size!=0 && a[heap[1][1]] && a[heap[1][1]]->next){ /*&& heap[1][1])*/
	    temp = a[heap[1][1]]->next;
	//    printf("%lld\n",heap[1][1]);
	}
    }
    if(dist[q]==-1)
    {
	printf("NO\n");
	return;
    }
    printf("%lld\n",dist[q]);
}
/*clear-------------------------------------------------------------------------------------------*/
int main()
{
    ll m,n;
    s(n);
    s(m);
    ll i,u,v,w;
    f(i,m)
    {
	s(u);
	s(v);
	s(w);
	insert(u,v,w);
    }
 //   print();
    ll S,T;
    s(S);
    s(T);
    size=0;
    init_dijkstra();
    dijkstra(S,T);
    return 0;
}
void print()
{
    ll i;gp temp;
    for(i=0;i<1000001;i++)
    {
	if(a[i]!=NULL)
	{
	    temp=a[i];
	    while(temp->next!=NULL)
	    {
		printf("%lld(%lld)->",temp->val,temp->weight);
		temp=temp->next;
	    }
	    printf("%lld(%lld)\n",temp->val,temp->weight);
	}
    }
}
