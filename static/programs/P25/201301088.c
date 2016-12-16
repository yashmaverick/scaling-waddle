#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct node
{
	int src,dest,wt;
}node;

void merge(node a[],int f,int m,int l)
{
	int i=f,j=m+1,k=0;
	node c[l-f+1];
	while(i<=m && j<=l)
		if(a[i].wt<a[j].wt)
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	while(i<=m)
		c[k++]=a[i++];
	while(j<=l)
		c[k++]=a[j++];
	for(i=f,k=0;i<=l;i++,k++)
		a[i]=c[k];
	return;
}

void msort(node a[],int f,int l)
{
	if(f<l)
	{
		int m=(f+l)/2;
		msort(a,f,m);
		msort(a,m+1,l);
		merge(a,f,m,l);
	}
	return;
}

long long ans = 0;

int comp[100011];
int root(int n)
{
	if(comp[n] == n)
		return n;
	comp[n] = root(comp[n]);
	return comp[n];
}

int main()
{
	int n,m,u,v,w,i;
       	scanf("%d%d",&n,&m);
	node e[m];
	for(i = 0 ; i < m ; i++)
	{
		scanf("%d%d%d",&u,&v,&w); u--; v--;
		e[i].src = u;
		e[i].dest = v;
		e[i].wt = w;
	}
	if(m < n-1)
	{
		puts("-1");
		return 0;
	}
	msort(e,0,m-1);
	int weight[100011],j;
	for(i = 0 ; i < n ; i++) comp[i] = i;
	for(i = 0 , j = 0 ; i < m ; i++)
		if(root(comp[e[i].src]) != root(comp[e[i].dest]))
		{
			weight[j++] = e[i].wt;
			comp[root(comp[e[i].dest])] = root(comp[e[i].src]);
		}
	if(j < n-1)
	{
		puts("-1");
		return 0;
	}
	for(i = 0 ; i < j ; i++)
		ans += weight[i];
	printf("%lld\n",ans);
	return 0;
}
