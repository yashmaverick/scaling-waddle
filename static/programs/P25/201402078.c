#include<stdio.h>
typedef struct node
{
	long long int v1,v2,wt;
}node;
node temp[1000001],a[1000001],edge[1000001];
long long int rank[100001],parent[100001];
long long int top(long long int d)
{
	while(d!=parent[d])
		d=parent[d];
	return d;
}
long long int check(long long int p,long long int q)
{
	if(top(p)==top(q))
		return 0;
	else
		return 1;
}
void insert(long long int l,long long int m)
{
	l=top(l);
	m=top(m);
	if(rank[l]>rank[m])
		parent[m]=l;
	else if(rank[m]>rank[l])
		parent[l]=m;
	else
	{
		parent[l]=m;
		rank[m]++;
	}
}
void sort(node c[],long long int start,long long int mid,long long int end)
{
	int i,m,k,l;
	l=start;
	i=start;
	m=mid+1;
	while((l<=mid)&&(m<=end))
	{
		if(c[l].wt<=c[m].wt)
		{
			temp[i]=c[l];
			l++;
		}
		else
		{
			temp[i]=c[m];
			m++;
		}
		i++;
	}
	if(l>mid)
		for(k=m;k<=end;k++)
		{
			temp[i]=c[k];
			i++;
		}
	else
		for(k=l;k<=mid;k++)
		{
			temp[i]=c[k];
			i++;
		}
	for(k=start;k<=end;k++)
		c[k]=temp[k];
}
void part(node c[],long long int start,long long int end)
{
	long long int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		part(c,start,mid);
		part(c,mid+1,end);
		sort(c,start,mid,end);
	}
}

int main()
{
	long long int n,m,x,y,z,i,sum=0,count=0;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		edge[i].v1=x;
		edge[i].v2=y;
		edge[i].wt=z;
	}
	part(edge,1,m);
	for(i=1;i<=m;i++)
	{
		if(check(edge[i].v1,edge[i].v2))
		{
			sum+=edge[i].wt;
			insert(edge[i].v1,edge[i].v2);
			count++;
		}
	}
	if(count==n-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
