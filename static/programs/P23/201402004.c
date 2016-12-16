#include<stdio.h>
#include<stdlib.h>
#define ll long long int

struct node
{
	struct node* prev;
	struct node* next;
	ll val;
	ll weight;
};

struct list
{
	struct node* start;
	struct node* end;
};

struct list* l[1000100];
ll heap[1000100];
ll size;

void insert_list(struct list* l, ll val, ll weight)
{
	struct node *new=(struct node*)(malloc(sizeof(struct node)));
	if(l->end!=NULL)
	{
	    l->end->next=new;
	    new->prev=l->end;
	    new->val=val;
	    new->weight=weight;
	    new->next=NULL;
	    l->end=new;
	}
	else
	{
	    l->end=new;
	    l->start=new;
	    new->val=val;
	    new->weight=weight;
	    new->next=NULL;
	}
	
	return;
}

void show(struct list* l)
{
    struct node *i;
    if(l==NULL)return;
    for(i=l->start;i!=NULL;i=i->next)printf("Next node %lld\n",i->val);
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

void insert_heap(ll val)
{
        size++;
        heap[size]=val;
        ll now=size;
        while(heap[now/2]>val&&now/2!=0) 
        {
                heap[now]=heap[now/2];
                now /= 2;
        }
        heap[now]=val;
}

ll deletemin()
{
        ll child,now,min,last;
        min=heap[1];
        last=heap[size];
        size--;
        for(now=1;now*2<=size ;now=child)
        {
                child=now*2;
                if(child!=size&&heap[child+1]<heap[child])child++;
                if(last>heap[child])heap[now]=heap[child];        
                else break;
        }
        heap[now]=last;
        return min;
}

ll order[1000000];
ll oi;
ll cnt=0;
ll indeg[1000000];

void topology()
{
    ll u,v;
    cnt=0;    
	while(size>0) 
	{
		u=deletemin();
		order[oi++]=u;
		cnt++;
		struct node* i;
        for(i=l[u]->start;i!=NULL;i=i->next)
		{
			v = i->val;
			indeg[v]--;
			if(indeg[v]==0)insert_heap(v);
		}
	}


}

int main()
{
    ll i,j,k,u,v,n,m;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<=n+1;i++){l[i]=(struct list*)(malloc(sizeof(struct list)));l[i]->start=l[i]->end=NULL;}

    size = 0;
    heap[0]= -10000000000;
        
	for(i=0;i<m;i++) 
	{
		scanf("%lld %lld",&u,&v);
		insert_list(l[u],v,1);
		indeg[v] += 1;
	}
	
	for(i=1; i<=n; i++)
		if(indeg[i]==0)
			insert_heap(i);
	topology();
	printf("%lld",order[0]);
	for(i=1;i<n;i++)printf(" %lld", order[i]);
	printf("\n");
	return 0;


}
