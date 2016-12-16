#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000000000000000
typedef long long int LL;
typedef struct bogi{
    int nu;
    LL weight;
    struct bogi* next;
}name;
typedef struct heap{
    LL value;
    int node;
}pair;
typedef name* ptr;
ptr A[1000005];
int marker[1000005];
LL dist[1000005];
pair heap[1000005];
int ref[1000005];
void swap(int i,int j)
{
    ref[heap[i].node]=j;
    ref[heap[j].node]=i;
    pair c=heap[i];
    heap[i]=heap[j];
    heap[j]=c;
}
LL min(LL a,LL b)
{
    if(a<b)
    {
	return a;
    }
    else
    {
	return b;
    }
}
int count;
void deletemin()
{
    heap[1]=heap[count];
    ref[heap[count].node]=1;
    heap[count].value=0;
    heap[count].node=-1;
    count--;
    int parent=1;
    int child1=2;
    int child2=3;
    while(1)
    {
	if(child1<=count&&child2<=count)
	{
	    if(heap[parent].value>min(heap[child1].value,heap[child2].value))
	    {
		if(heap[child1].value<heap[child2].value)
		{
		    swap(parent,child1);
		    parent=child1;
		    child1=2*parent;
		    child2=2*parent+1;

		}
		else
		{
		    swap(parent,child2);
		    parent=child2;
		    child1=2*parent;
		    child2=2*parent+1;
		}
	    }
	    else
	    {
		break;
	    }
	}
	else if(child1<=count&&child2>count)
	{
	    if(heap[parent].value>heap[child1].value)
	    {
		swap(parent,child1);
		parent=child1;
		child1=2*parent;
		child2=2*parent+1;
	    }
	    else
	    {
		break;
	    }
	}
	else if (child1>count&&child2>count)
	{
	    break;
	}
    }
}
ptr insert(int n,LL w,ptr root)
{
    ptr tmp=(ptr)malloc(sizeof(name));
    tmp->nu=n;
    tmp->weight=w;
    tmp->next=root;
    return tmp;
}
void print(ptr root)
{

    ptr tmp=root;
    while(tmp!=NULL)
    {
	printf("%d ",tmp->nu);
	tmp=tmp->next;
    }
    printf("\n");
}
void update(int x,LL d)
{
    int position=ref[x];
    int parent=position/2;
    heap[position].value=d;
    while(heap[parent].value>heap[position].value)
    {
	swap(position,parent);
	position=position/2;
	parent=position/2;
    }

}
LL dikstra(int s,int d)
{
    //    int i;
    ptr tmp;
    dist[s]=0;
    swap(s,1);
    heap[1].value=0;
    while(1)
    {
	int currentnode=heap[1].node;
	tmp=A[heap[1].node];
	while(tmp!=NULL)
	{
	    if(marker[tmp->nu]==0)
	    {
		if(dist[tmp->nu]>(dist[currentnode]+tmp->weight))
		{
		    dist[tmp->nu]=dist[currentnode]+tmp->weight;
		    update(tmp->nu,dist[tmp->nu]);
		}
	    }

	    /*	    for(i=1;i<=6;i++)
		    {
		    printf("%lld ",dist[i]);
		    }
		    printf("\n");*/
	    tmp=tmp->next;
	}
	marker[heap[1].node]=1;
	if(heap[1].node==d)
	{
	    return dist[d];
	}
	deletemin();
    }
}
int main()
{
    int t;
    int n,m,i,x,y;
    LL w,ans;
    heap[0].value=1-MAX;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
	ref[i]=i;
	heap[i].node=i;
	heap[i].value=MAX;
	dist[i]=MAX;
	marker[i]=0;
	A[i]=NULL;
    }
    count=n;
    for(i=0;i<m;i++)
    {
	scanf("%d %d %lld",&x,&y,&w);
	A[x]=insert(y,w,A[x]);
	//	    A[y]=insert(x,w,A[y]);
    }
    scanf("%d %d",&x,&y);
    ans=dikstra(x,y);
    /*	for(i=1;i<=n;i++)
	{
	printf("%lld ",dist[i]);
	}
	printf("\n");*/
    if(ans==MAX)
    {
	printf("NO\n");
    }
    else
    {
	printf("%lld\n",ans);
    }
    return 0;
}

