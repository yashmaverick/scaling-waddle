#include<stdio.h>
#include<stdlib.h>
#define ll long long int

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

void insert(struct list* l, int val)
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
    for(i=l->start;i!=NULL;i=i->next)printf("Next node %lld\n",i->val);
    printf("List ends here.\n");
}

void clear(struct list* l)
{
    struct node *i;
    if(l==NULL)return;
    for(i=l->start->next;i!=NULL;i=i->next)free(i->prev);
    free(l);
    return;
}

ll vis[1000100];
struct list* l[1000100];
int h[1000100];		

void dfs(ll depth,ll val)
{
	if(h[val]!=-1)return;
	h[val]=depth;
	struct node* i;
	for(i=l[val]->start;i!=NULL;i=i->next)
	    dfs(depth+1,i->val);
}

int main()
{

	ll t,n,i,inp1,inp2,d;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==0){printf("0\n");continue;}
		if(n==1){printf("1\n");continue;}
	    if(n==2){printf("2\n");continue;}
        for(i=0;i<=n+2;i++){l[i]=(struct list*)(malloc(sizeof(struct list)));l[i]->start=l[i]->end=NULL;}
		for(i=1;i<n;i++)
		{
			scanf("%lld %lld",&inp1,&inp2);
			insert(l[inp1],inp2);
			insert(l[inp2],inp1);
		}
        for(i=1;i<n+10;i++)h[i]=-1;
	    dfs(1,1);
	    inp1=-1;
	    inp2=-1;
	    for(i=1;i<n+10;i++)if(h[i]>inp1){inp1=h[i];inp2=i;}
	    for(i=1;i<n+10;i++)h[i]=-1;
	    dfs(1,inp2);
	    for(i=1;i<n+10;i++)if(h[i]>inp1){inp1=h[i];inp2=i;}
	    printf("%lld\n",inp1);
	    for(i=1;i<=n;i++)clear(l[i]);	
	}

	return 0;	
}
