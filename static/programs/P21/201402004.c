#include <stdio.h>
#include <stdlib.h>
#define ll long long int
struct edge
{
	ll e,p;
};

ll i,j,k,n,m,a,b,c,d;

struct node
{
	struct node* prev;
	struct node* next;
	struct edge val;
};

struct list
{
	struct node* start;
	struct node* end;
};

struct list* l[1000100];
struct edge heap[1000100];
ll size;
ll mark[1000100];
ll dist[1000100];

void insert_list(struct list* l, struct edge val)
{
	struct node *new=(struct node*)(malloc(sizeof(struct node)));
	if(l->end!=NULL)
	{
	    l->end->next=new;
	    new->prev=l->end;
	    new->val=val;
	    new->next=NULL;
	    l->end=new;
	}
	else
	{
	    l->end=new;
	    l->start=new;
	    new->val=val;
	    new->next=NULL;
	}
	
	return;
}

void show(struct list* l)
{
    struct node *i;
    if(l==NULL)return;
    for(i=l->start;i!=NULL;i=i->next)printf("Next node %lld\n",i->val.e);
    printf("List ends here.\n");
}

void clear(struct list* l)
{
    struct node *i;
    if(l==NULL)return;
    l=NULL;
    //for(i=l->start->next;i!=NULL;i=i->next)free(i->prev);
    free(l);
    return;
}

void insert_heap(struct edge val)
{
        size++;
        heap[size]=val;
        ll now=size;
        while(heap[now/2].p>val.p&&now/2!=0) 
        {
                heap[now]=heap[now/2];
                now /= 2;
        }
        heap[now]=val;
}

struct edge deletemin()
{
        ll child,now;
        struct edge min,last;
        min=heap[1];
        last=heap[size];
        size--;
        for(now=1;now*2<=size ;now=child)
        {
                child=now*2;
                if(child!=size&&heap[child+1].p<heap[child].p)child++;
                if(last.p>heap[child].p)heap[now]=heap[child];        
                else break;
        }
        heap[now]=last;
        return min;
}

void dijsktra(ll s)
{
    for(i=0;i<1000000;i++){dist[i]=-1;mark[i]=0;}
    struct edge start;
    start.e=s;
    start.p=0;
    insert_heap(start);
    dist[s]=0;
    while(size>0)
    {
        struct edge x=deletemin();
        if(mark[x.e]==1)continue;
        mark[x.e]=1;
        struct node* i;
        for(i=l[x.e]->start;i!=NULL;i=i->next)
        {
            if(dist[i->val.e]<0||dist[i->val.e]>dist[x.e]+i->val.p)
            {
                dist[i->val.e]=dist[x.e]+i->val.p;
                insert_heap(i->val);
            }
       }
    }
}

int main()
{	
   
		scanf("%lld %lld",&n,&m);
		for(i=0;i<=n+1;i++){l[i]=(struct list*)(malloc(sizeof(struct list)));l[i]->start=l[i]->end=NULL;}
	
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&b,&c,&d);
			struct edge e1,e2; 
			e1.e=b;
			e2.e=c;
			e1.p=e2.p=d;
			insert_list(l[b],e2);
		}
		scanf("%lld %lld",&b,&c);
		
		dijsktra(b);
		if(dist[c]==-1) printf("NO\n");
		else printf("%lld\n", dist[c]);
		for(i=0;i<=n;i++)clear(l[i]);
    
    return 0;
}
