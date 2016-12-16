#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#include<limits.h>
#define set(ch,a) memset(ch,a,sizeof(ch))
#define ml(a) (a*)malloc(sizeof(a))
typedef struct node{
	int lvl,ele,ct;
	struct node* r;struct node* l;
}node;
typedef struct trip{
	int i,j,w;
}trip;
int p[100005],h[100005];
static int comp(const void* a,const void* b)
{	trip a1=*((trip*)a);trip b1=*((trip*)b);
	if(a1.w==b1.w)
	{	if(a1.i==b1.i)
			return a1.j-b1.j;
		return a1.i-b1.i;
	}
	return a1.w-b1.w;
}
void merge(int i,int j)
{	while(p[i]>=0)i=p[i];
	while(p[j]>=0)j=p[j];
	if(h[i]<h[j] )p[i]=j;
	else if(h[i]>h[j] )p[j]=i;
	else {p[i]=j;h[j]++;}
}
int find(int a)
{	if(p[a]<0)
		return a;
		p[a]=find(p[a]);
	return p[a];
}

int main()
{	int i,n,m;trip ar[100001];
	sc(n);sc(m);int x,y;long long j=0;
	f(i,0,n+2){p[i]=-i-1;h[i]=0;}
	f(i,0,m)
	{	sc(ar[i].i);sc(ar[i].j);sc(ar[i].w);}
	qsort(ar,m,sizeof(trip),comp);
	i=0;int c=0;
	while(i<m && c<n-1)
	{if((x=find(ar[i].i))!=(y=find(ar[i].j)))
		{j+=ar[i].w;merge(ar[i].i,ar[i].j);c++;
		}
		i++;}
	if(c>=n-1)
	printf("%lld\n",j);
	else printf("-1\n");
	return 0;
}

