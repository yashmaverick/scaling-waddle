#include<stdio.h>
#include<stdlib.h>
#define size 100005

typedef long long int lli;
struct node
{
    lli data;
    lli wt;
    struct node *next;
};

typedef struct node node;
typedef node* link;
//Global VARs
link head[size];
lli min[2][size],end=0;//min[0][] = to place min[1][] is weight
lli dih[size];//number of times dijk performed
lli answt[size],n_nodes;
lli ref[size];

//Functions
link insert(link, lli, lli);
void minin(lli, lli);
void mindel();
void minupd(lli, lli);
void reset();
void dijk(lli);
void call();
void showans();
void swap(lli,lli);

void swap(lli a,lli b)
{
    lli tto,twt,tref;

    tto=min[0][a];
    min[0][a]=min[0][b];
    min[0][b]=tto;

    twt=min[1][a];
    min[1][a]=min[1][b];
    min[1][b]=twt;

    tref=ref[min[0][a]];
    ref[min[0][a]]=ref[min[0][b]];
    ref[min[0][b]]=tref;
}



void showans()
{
    int i;
    for(i=1;i<=n_nodes;i++)
	printf("%lld ",answt[i]);
    printf("\n");
}

void reset()
{
    lli i;
    for(i=1;i<=size;i++)
	answt[i]=-1;

    for(i=1;i<=size;i++)
	head[i]=NULL;

    for(i=1;i<=size;i++)
	ref[i]=0;

    end=0;

    for(i=1;i<=size;i++)//for n nodes
	dih[i]=0;//dijk performed on nothing
}

link insert(link head,lli val,lli wt)
{
    link temp = (link) malloc(sizeof(node));
    temp->data=val;
    temp->wt=wt;
    temp->next=head;
    return temp;
}

void minin(lli to,lli wt)
{
    end++;
    ref[to]=end;
    min[0][end]=to;
    min[1][end]=wt;
    lli cur=end;
    while(cur>1 && min[1][cur/2]>wt)
    {
	swap(cur,cur/2);
	cur/=2;
    }
}

void mindel()
{
    min[0][1]=min[0][end];
    min[1][1]=min[0][end];
    ref[min[0][1]]=1;
    ref[min[0][1]]=0;
    end--;
    lli cur=1;
    while(((cur*2)<=end && (min[1][cur*2]<=min[1][cur])) || ((min[1][(cur*2)+1]<=min[1][cur]) && (((cur*2)+1)<=end)))
    {
	lli index;
	if(((cur*2)+1)>end)
	    index=cur*2;
	else
	    index=min[1][cur*2]<=min[1][(cur*2)+1]?cur*2:((cur*2)+1);
	swap(cur,index);
	cur=index;
    }
}

void minupd(lli to,lli wt)
{
    lli cur;
    cur = ref[to];
    min[1][cur]=wt;
    while(cur>1 && min[1][cur/2] > wt)
    {
	swap(cur,cur/2);
	cur/=2;
    }
}

void dijk(lli on)
{
    lli to,wt;
    link temp = head[on];
    while(temp!=NULL)
    {
	to = temp->data;
	wt = temp->wt;
	if(answt[to]==-1)
	    answt[to]=answt[on]+wt;
	else
	    answt[to] = (answt[on]+wt)<answt[to]?(answt[on]+wt):answt[to];
	if(ref[to]==0)
	    minin(to,answt[to]);
	else
	    minupd(to,answt[to]);
	temp=temp->next;
    }
}
int main()
{
	lli n,m,i,x,y,w;
	scanf("%lld%lld",&n,&m);
	n_nodes=n;
	reset();
	for(i=0;i<m;i++)
	{
	    scanf("%lld%lld%lld",&x,&y,&w);
	    head[x]=insert(head[x],y,w);
	}

	lli S,T;
	scanf("%lld%lld",&S,&T);
	minin(S,0);
	answt[S]=0;
	while(end>0)
	{
	    lli on;
	    on=min[0][1];
	    mindel();
	    if(dih[on]==0)
	    {
		dih[on]=1;
		dijk(on);
	    }
	}
	if(answt[T]==-1)
	    printf("NO\n");
	else
	    printf("%lld\n",answt[T]);
    return 0;
}
