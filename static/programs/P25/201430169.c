#include<stdio.h>
typedef struct node
{
	int v1,v2,wt;
}node;

int P[1000001],rank[1000001];
node edge[1000001];
void swap(int x,int y)
{
	node t=edge[x];
	edge[x]=edge[y];
	edge[y]=t;
}
void qusort(int f,int l)
{
	if(f<l-1)
	{
		int i,j,mid,pivot;
		mid=(f+l)/2;
		swap(mid,l-1);
		pivot=edge[l-1].wt;
		int p,q;
		p=f;
		q=l-2;
		while(p<=q)
		{
			while(edge[p].wt<pivot)
				p++;
			while(edge[q].wt>pivot)
				q--;
			if(p<q)
				swap(p,q);
			if(edge[p].wt==pivot && edge[q].wt==pivot)
			{
				p++;
				q--;
			}
		}
		swap(p,l-1);
		qusort(f,p);
		qusort(p+1,l);
	}
}
int find(int x)
{
/*	if(P[x]==x)
		return x;
	int y=find(P[x]);
	P[x]=y;*/
	if(P[x]!=x)
	P[x]=find(P[x]);
	return(P[x]);
}
void merge(int x,int y)
{
	int p1,p2;
	p1=find(x);
	p2=find(y);
	if(rank[p1]<rank[p2])
		P[p1]=p2;
	else if(rank[p1]>rank[p2])
		P[p2]=p1;
	else
	{
		P[p2]=p1;
		rank[p1]++;
	}
}

int main()
{
	int n,m,i,j,a,b,w,sum=0,count=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		edge[i].v1=a;
		edge[i].v2=b;
		edge[i].wt=w;
	}
	qusort(0,m);
	for(i=1;i<=n;i++)
		P[i]=i;
	for(i=0;i<m;i++)
	{
		if(find(edge[i].v1)!=find(edge[i].v2))
		{
			merge(edge[i].v1,edge[i].v2);
			sum+=edge[i].wt;
			count++;
		}
	}
	if(count==n-1 || n==1)
		printf("%d\n",sum);
	else
		printf("-1\n");
	return 0;
}	
