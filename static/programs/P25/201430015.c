#include<stdio.h>
int parent[100003],rank[100003];
int N;

int find(int x)
{
	int i,x1,x2;
	i=x;
	while(parent[i]!=i)
	{
		x1=i;
		i=parent[i];
		parent[x1]=i;
	}
	return i;
}

void setunion(int x,int y)
{
	int py,px;
	py=find(y);
	px=find(x);
	if(rank[px]<rank[py])
	{
		parent[px]=py;
	}
	else if(rank[py]>rank[px])
	{
		parent[py]=px;
	}
	else
	{
		parent[px]=py;
		rank[py]++;
	}
}

void disparent()
{
	printf("parent: ");
	int i;
	for(i=1;i<=N;i++)
	{
		printf("%d ",parent[i]);
	}
	printf("\n");
}

void disrank()
{
	int i;
	printf("rank: ");
	for(i=1;i<=N;i++)
	{
		printf("%d ",rank[i]);
	}
	printf("\n");
}

typedef struct edge{
	int v1,v2;
	long long int weight;
}edge;

edge a[1000000];
void merge(edge a[],edge b[],edge res[],int m,int n)
{
	int k,i,j;
	k=0;
	i=0;
	j=0;
	while((i<m)&&(j<n))
	{
		if(a[i].weight<b[j].weight)
		{
			res[k++]=a[i++];
		}
		else
		{
			res[k++]=b[j++];
		}
	}
	if(i<m)
	{
		while(i<m)
		{
			res[k++]=a[i++];
		}
	}
	else
	{
		while(j<n)
		{
			res[k++]=b[j++];
		}
	}
}

void merge_sort(edge a[],int n)
{
	if(n<=1)
	{
		return;
	}
	int mid,i,j;
	mid=n/2;
	edge left[mid],right[n-mid];
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	j=0;
	for(i=mid;i<n;i++)
	{
		right[j]=a[i];
		j++;
	}
	merge_sort(left,mid);
	merge_sort(right,n-mid);
	merge(left,right,a,mid,n-mid);
}

int main()
{
	int m,n,i,u,v;
	long long int wt;
	int count_e,flag;
	long long int sum;
	sum=0;
	scanf("%d %d",&N,&m);
	for(i=1;i<=N;i++)
	{
		parent[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %lld",&u,&v,&wt);
		a[i].v1=u;
		a[i].v2=v;
		a[i].weight=wt;
	}
	merge_sort(a,m);
	count_e=0;
/*	for(i=0;i<m;i++)
	{
		printf("%d ",a[i].weight);
	}
	printf("\n");*/
	i=0;
	while((count_e<N-1)&&(i<m))
	{
//		disparent();
//		disrank();
		u=a[i].v1;
		v=a[i].v2;
		if(find(u)==find(v))
		{
			i++;
			continue;
		}
		else 
		{
			setunion(u,v);
			sum+=a[i].weight;
			count_e++;
			i++;
		}
	}
//	disparent();
	flag=0;
	for(i=2;i<=N;i++)
	{
		if(find(i)!=find(i-1))
		{
			printf("-1\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
	printf("%lld\n",sum);
	return 0;
}
