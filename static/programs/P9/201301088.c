#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	long long int wt,N,*m;
}node;

long long int n,mod;

void merge(node a[],long long int f,long long int m,long long int l)
{
	long long int i=f,j=m+1,k=0;
	node c[l-f+1];
	while(i<=m && j<=l)
		if(a[i].wt <= a[j].wt)
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

void msort(node a[],long long int f,long long int l)
{
	if(f<l)
	{
		long long int m=(f+l)/2;
		msort(a,f,m);
		msort(a,m+1,l);
		merge(a,f,m,l);
	}
	return;
}

int main()
{
	long long int i,j,w,k;
	scanf("%lld%lld",&n,&mod);
	node a[n];
	for(i=0;i<n;i++)
		a[i].wt=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&j);
		a[i].N=j;
		a[i].m= (long long int*) malloc(sizeof(long long int) * j);
		for(k=0;k<j;k++)
		{
			scanf("%lld",&w);
			a[i].wt=( (a[i].wt) % mod + w % mod )%mod;
			a[i].m[k]=w;
		}
	}
	msort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%lld\n",a[i].wt);
		for(j=0;j<a[i].N;j++)
			printf("%lld\n",a[i].m[j]);
		printf("\n");
	}
	return 0;
}
