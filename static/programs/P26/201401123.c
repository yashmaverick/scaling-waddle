#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
#define s(n) scanf("%d",&n)
#define d(n) n=(gp)malloc(1*sizeof(g))
#define f(i,n) for(i=0;i<n;i++)
typedef int ll;
typedef struct graph{
    ll val;
    struct graph* next;
    ll weight;
}g;
typedef g* gp;
gp a[10002];
int sieve[10002];
ll heap[2][100002];
ll visited[10002];
ll dist[10002];
ll size;
//ll indxe[10002];
/*CORRECT            CORRECT             CORRECT*/
void insertlist(ll,ll);
void insert(int x){
    int i;
    for(i=0;i<10;i++){
	if(sieve[(x-(x/1000)*1000)+i*1000]==-1)
	    insertlist(x,(x-(x/1000)*1000)+i*1000);
	if(sieve[(x-((x/100)%10)*100)+i*100]==-1)
	    insertlist(x,(x-((x/100)%10)*100)+i*100);
	if(sieve[(x-((x/10)%10)*10)+i*10]==-1)
	    insertlist(x,(x-((x/10)%10)*10)+i*10);
	if(sieve[(x-(x%10))+i]==-1)
	    insertlist(x,(x-(x%10))+i);
    }
    return ;
}


void insertlist(ll u,ll v)
{
    if(u/1000==0 || v/1000==0 || u==v)
	return ;
    gp t1;
    d(t1);
    t1->val=v;
    t1->weight=1;
    t1->next=a[u];
    a[u]=t1;
    return;
}
void makesieve()
{
    ll i,j;
    for(i=2;i*i<=9999;i++)
	for(j=2;i*j<=9999;j+=1)
	    sieve[i*j]=1;
}
void init_dijkstra()
{
    ll i;
    for(i=999;i<=10000;i++)
    {
	visited[i]=-1;
	dist[i]=-1;
    }
}
//heapify here: (shuffleUP)
int fl;
void insertheap(ll w,ll no, ll j)
{
    ll t1,t2,t3;
    heap[0][j]=w;
    heap[1][j]=no;
    if(j>1)
    {
	while(heap[0][j]<heap[0][j/2] && j>1)
	{
	    t1=heap[0][j];t2=heap[1][j];
	    heap[0][j]=heap[0][j/2];heap[1][j]=heap[1][j/2];
	    heap[0][j/2]=t1;heap[1][j/2]=t2;
	    j/=2;
	}
    }
}
ll minw,minv;
void deleteMin()
{
    ll t1,t2,t,T,t3,T3;
    //swap indxe of heap1,1 and heap 1,size
    heap[0][1]=heap[0][size];t2=heap[1][1]=heap[1][size];
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
	    t=heap[0][k];heap[0][k]=heap[0][j];heap[0][j]=t;
	    T=heap[1][k];heap[1][k]=heap[1][j];heap[1][j]=T;
	}
	k=j;
    }
}
/*CORRECT            CORRECT             CORRECT*/
void dijkstra(ll p,ll q)
{
    if(sieve[p]==1 || sieve[q]==1)
    {
	printf("Impossible\n");
	return;
    }
    size = 0;
    size++;
    heap[0][1]=0;
    heap[1][1]=p;
    dist[p]=0;
    while(size!=0)
    {
	if(visited[heap[1][1]]==-1)
	{
	    visited[heap[1][1]]=1;
	    gp t;
	    t=a[heap[1][1]];
	    ll d=heap[1][1];
	    deleteMin();
	    while(t!=NULL)
	    {
		if(visited[t->val]==-1)
		{
		    if(dist[t->val]==-1)
		    {
			dist[t->val]=dist[d]+t->weight;
			size++;
			insertheap(dist[d]+t->weight,t->val,size);
		    }
		    else if((dist[d]+t->weight)<dist[t->val])
		    {
			dist[t->val]=dist[d]+t->weight;size++;
			insertheap(dist[d]+t->weight,t->val,size);
		    }
		}
		t=t->next;
	    }
	}
	else if(visited[heap[1][1]]==1)
	    deleteMin();
	//size++;
	//insertheap(temp->weight,temp->val,size);
	if(visited[q]==1)
	    break;
    }
    if(visited[q]==-1)
	printf("Impossible\n");
    else
	printf("%d\n",dist[q]);
    return;
}
/*clear-------------------------------------------------------------------------------------------*/

void print();
int main()
{
    /* make  a sieve before running test cases */
    ll tennisball;
    int o;
    for(o=0;o<10001;o++)
	a[o]=NULL;
    for(tennisball=1000;tennisball<10000;tennisball++)
	sieve[tennisball]=-1;
    makesieve();
    ll t,x,y,i,j,k;
    for(i=1000;i<=9999;i++)
    {
	if(sieve[i]==-1)
	{
	    insert(i);
	}
    }
    //print();
    s(t);
    while(t--)
    {
	init_dijkstra();
	s(x);
	s(y);
	//printf("%d %d\n",sieve[x],sieve[y]);
	dijkstra(x,y);
    }
    return 0;
}

void print()
{
    ll i;gp temp;
    for(i=0;i<10000;i++)
    {
	if(a[i]!=NULL)
	{
	    temp=a[i];
	    while(temp->next!=NULL)
	    {
		printf("%d(%d)->",temp->val,temp->weight);
		temp=temp->next;
	    }
	    printf("%d(%d)\n",temp->val,temp->weight);
	}
    }
}
