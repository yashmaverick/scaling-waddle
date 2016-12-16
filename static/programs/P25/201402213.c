#include<stdio.h>
#include<stdlib.h>
long long parent[1000000];
long long rank[1000000];
long long count[1000000];
typedef struct tuple{
	long long x,y,w;
}tuple;
tuple x[1000000];
int cmpfunc(const void *a,const void *b)
{
	tuple *p1,*p2;
	p1=(tuple *)a;
	p2=(tuple *)b;
	if(p1->w<p2->w)
		return -1;
	else if(p1->w>p2->w)
		return 1;
	else
		return 0;
}
long long find(long long x)
{
	if(parent[x]==x)
		return x;
	parent[x]=find(parent[x]);
	return parent[x];
}
int main()
{
	long long n,q;
	scanf("%lld%lld",&n,&q);
	long long i;
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(i=0;i<q;i++)
		scanf("%lld%lld%lld",&x[i].x,&x[i].y,&x[i].w);
	qsort(x,q,sizeof(tuple),cmpfunc);
	long long sum=0;
	for(i=0;i<q;i++)
	{
		long long px=find(x[i].x);
		long long py=find(x[i].y);
		if(px==py)
			continue;
		sum+=x[i].w;
//		printf("%d %d %d %d\n",x[i].x,x[i].y,px,py);
		if(rank[px]<rank[py])
		{
			parent[px]=py;
			count[py]+=(count[px]+1);
		}
		else if(rank[py]<rank[px])
		{
			parent[py]=px;
			count[px]+=(count[py]+1);
		}
		else
		{
			parent[py]=px;
			count[px]+=(count[py]+1);
			rank[py]++;
		}
	}
	long long vis=0;
	for(i=1;i<=n;i++)
		if(parent[i]==i)
			vis++;
	if(vis!=1)
		printf("-1\n");
	else
		printf("%lld\n",sum);
	return 0;
}
