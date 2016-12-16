#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ll long long int
#define push(num) stack[++top]=num;
#define pop() stack[top--]

ll stack[1000100],top;
struct list* a[1000100];
struct list* b[1000100];
ll vis[1000000];

struct node
{
	struct node* prev;
	struct node* next;
	ll val;
};

struct list
{
	struct node* start;
	struct node* end;
};

void insert_list(struct list* l, ll val)
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

ll dfs1(i)
{
    push(i);
    ll v;
	ll no_vis=1;
	while(top!=-1)
	{
	    
	    v=pop();
	    vis[v]=1;
		struct node* i;
		for(i=a[v]->start;i!=NULL;i=i->next)
		{
		    if(vis[i->val]==0)
		    {
			    push(i->val);
			    no_vis++;
			    vis[i->val]=2;
		    }
		}
    }
	return no_vis;
}

ll dfs2(i)
{
    push(i);
	ll no_vis=1;
	ll v;
	while(top!=-1)
	{
	    v=pop();
	    vis[v]=1;
		struct node* i;
		for(i=b[v]->start;i!=NULL;i=i->next)
		{
		    if(vis[i->val]==0)
		    {
			    push(i->val);
			    no_vis++;
			    vis[i->val]=2;
		    }
		}
    }
	return no_vis;
}

void init()
{
    ll i;
    for(i=0;i<=1000000;i++)
	    vis[i]=0;
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
    free(l);
    return;
}

ll n;

void make_list()
{
    ll i,j,cnt,m;
    scanf("%lld",&n);
    for(i=0;i<=n+1;i++)
    {
        a[i]=(struct list*)(malloc(sizeof(struct list)));
        a[i]->start=a[i]->end=NULL;
        b[i]=(struct list*)(malloc(sizeof(struct list)));
        b[i]->start=b[i]->end=NULL;
    }
    for(i=1;i<=n;i++)
	{
	    scanf("%lld",&cnt);
	    for(j=0;j<cnt;j++)
	    {
		    scanf("%lld",&m);
		    insert_list(a[m],i);
		    insert_list(b[i],m);
	    }
	}  

}



int main()
{
    ll no_vis,i,t;
    scanf("%lld",&t);
    while(t--)
    {
	    make_list(); 
	    for(i=1;i<=n;i++)
	    {
	        init();
	        no_vis=dfs1(i);
	        if(no_vis==n)
		        break;
	    }
	    if(i<=n)
	    {   
	        init();
	        no_vis=dfs2(i);
	        printf("%lld\n",no_vis);
	    }
	    else
    	{
    	    printf("0\n");
    	}
    	for(i=0;i<=n;i++){clear(a[i]);clear(b[i]);}
    }
    return 0;
}
