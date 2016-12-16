#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	long long int f,l,w;
}node;
long long int parent[100005],valid[100005];
void merge(node a[],long long int low,long long int mid,long long int high,node c[])
{
	
	long long int i=low,j=mid+1,k=0,x;
	while(i<=mid && j<=high)
	{
		if(a[i].w < a[j].w)
		{
//			for(x=0;x<3;x++)
				c[k] = a[i];
			k++;
			i++;
		}
		else {
//			for(x=0;x<3;x++)
				c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid) {
//		for(x=0;x<3;x++)
			c[k]= a[i];
		i++;
		k++;
	}
	while(j<=high){
//		for(x=0;x<3;x++)
			c[k]= a[j];
		k++;
		j++;
	}
}
void mergesort(node a[],long long int low,long long int high)
{
	
	if(high <= low)
		return;
	long long int i=0,x;
	node c[high-low+1];
	long long int mid = (low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high,c);
	for(i=low;i<=high;i++)
//	{
//		for(x=0;x<3;x++)
			a[i]=c[i-low];
//	}
}
long long int Find(long long int i)
{
	if(parent[i]==i)
		return i;
	else
		return Find(parent[i]);
}
long long int is_connected(long long int x,long long int y)
{
	if(Find(x)==Find(y))
		return 1;
	else 
		return 0;
}
long long int union_set(long long int a,long long int b) 
{
	long long int k;
	k=Find(b);
	parent[k]=a;
	return 0;
}

int main()
{
	long long int n,q,x,y,test,i;
	node A[100005];
	long long int edges,sum=0,nodes;
	scanf("%lld%lld",&nodes,&edges);
	for(i=0;i<=nodes;i++)
	{
		parent[i]=i;
	}
	for(i=0;i<edges;i++)
	{
		valid[i]=1;
		scanf("%lld",&A[i].f);
		scanf("%lld",&A[i].l);
		scanf("%lld",&A[i].w);
	}
//	printf("----------\n");
	mergesort(A,0,edges-1);
//	for(i=0;i<edges;i++)
//		printf("%lld %lld %lld\n",A[i]);
	for(i=0;i<edges;i++)
	{
		x=A[i].f;
		y=A[i].l;
		if(is_connected(x,y)==0)
			union_set(x,y);
		else
			valid[i]=0;
	}
	int count=0;
	int flag=0;
	for(i=0;i<edges;i++)
	{
		if(valid[i]==1){
			sum=sum+A[i].w;
			count++;
		}
		if(count==nodes-1){
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
