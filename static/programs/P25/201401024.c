#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100005
#define INF 10000000000000
typedef struct node
{
    struct node *next;
    int val;
    int w;
}node;
node *arr[MAX];
node *insert(node *root,long long int a,long long int b)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->val=a;
    temp->w=b;
    temp->next=root;
    return temp;
}
long long int size=-1;
long long int d[MAX]={INF};
long long int visited[MAX]={0};
typedef struct pyque
{
    long long int val;
    long long int ind;
}pyque;
pyque a[MAX];
int back[MAX];
void swap(pyque *a,pyque *b)
{
    pyque temp=*a;
    *a=*b;
    *b=temp;
}
long long int min(long long int a,long long int b)
{
    if(a<b)return a;
    return b;
}
void correct1(long long int n)
{
    if((n-1)/2>=0 && a[(n-1)/2].val>a[n].val)
    {
        back[a[n].ind]=(n-1)/2;
        back[a[(n-1)/2].ind]=n;
        swap(&a[n],&a[(n-1)/2]);
        correct1((n-1)/2);
    }
}
void correct2(long long int n)
{
    if((2*n+1)>size)return;
    long long int x=2*n+1;
    if((2*n+2)<=size && a[x].val>a[2*n+2].val)
        x=2*n+2;
    if(a[x].val<a[n].val)
    {
        back[a[n].ind]=x;
        back[a[x].ind]=n;
        swap(&a[n],&a[x]);
        correct2(x);
    }
}
void heapinsert(long long int x,long long int y)
{
    size++;
    a[size].ind=x;
    a[size].val=y;
    back[a[size].ind]=size;
    correct1(size);
}
void heapupdate(long long int x,long long int y)
{
    long long int h=back[x];
    a[h].val=y;
    a[h].ind=x;
    correct1(h);
    correct2(h);
}
pyque getmin()
{
    pyque x=a[0];
    a[0]=a[size];
    size--;
    correct2(0);
    return x;
}
void prim(long long int a)
{
    long long int i;
    for(i=0;i<MAX;i++)
        d[i]=INF;
    d[a]=0;
    heapinsert(a,d[a]);
    while(size!=-1)
    {
        pyque pp=getmin();
        long long int p=pp.ind;
        visited[p]=2;
        node *temp=arr[p];
        while(temp!=NULL)
        {
            if(visited[temp->val]!=2)
                d[temp->val]=min(d[temp->val],temp->w);
            if(visited[temp->val]==0)
            {
                visited[temp->val]=1;
                heapinsert(temp->val,d[temp->val]);
            }
            else if(visited[temp->val]==1)
                heapupdate(temp->val,d[temp->val]);
            temp=temp->next;
        }
    }
}
int main()
{
	long long int i,n,m,flag=0;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		long long int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		arr[u]=insert(arr[u],v,w);
		arr[v]=insert(arr[v],u,w);
	}
	prim(1);
	long long ans=0;
	for(i=1;i<=n;i++)
    {
        ans+=d[i];
        if(d[i]==INF)
            flag=1;
    }
    if(flag)printf("-1\n");
    else
	printf("%lld\n",ans);
	return 0;
}
