#include<stdio.h>
#include<stdlib.h>
struct node
{
	long long int n1;
	long long int n2;
	long long int weight;
};
typedef struct node node;
node tmp[1000001]={};
long long int parent[1000001]={};
long long int l[1000001]={};
void mergesort(node a[],long long int s,long long int e)
{
	long long int k=0;
	if(s==e)
		return ;
	long long int mid=(s+e)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	long long int j=mid+1;
	long long int i=s;
	while(i<=mid || j<=e)
	{
		if(i>mid)
			tmp[k++]=a[j++];
		else if(j>e)
			tmp[k++]=a[i++];
		else
		{
			if(a[i].weight<a[j].weight)
				tmp[k++]=a[i++];
			else
				tmp[k++]=a[j++];
		}
	}
	long long int p;
	for(p=0;p<k;p++)
		a[s+p]=tmp[p];
}
long long int cycle(long long int i)
{
	if(parent[i]!=i)
		parent[i]=cycle(parent[i]);
	return parent[i];
}
int main()
{
	long long int n,m,i,j,siz=0,flag=0,count=0;
	long long int ret=0;
	scanf("%lld%lld",&n,&m);
	node a[m+1];
	if(n==1)
	{
		flag=1;
		printf("%0\n");
	}
	if(flag==0)
	{
		for(i=1;i<=n;i++)
		{
			parent[i]=i;
			l[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&(a[i].n1));
			scanf("%lld",&(a[i].n2));
			scanf("%lld",&(a[i].weight));
		}
		mergesort(a,1,m);
		char visited[n+1];
		for(i=1;i<=n;i++)visited[i]=0;
		for(i=1;i<=m;i++)
		{
			long long int x=cycle(a[i].n1);
			long long int y=cycle(a[i].n2);
			if(x!=y)
			{
				visited[a[i].n1]=visited[a[i].n2]=1;
				siz++;
				ret=ret+a[i].weight;
				if(l[x]==l[y])
				{
					parent[y]=x;
					l[x]++;
				}
				else if(l[x]<l[y])
					parent[x]=y;
				else if(l[x]>l[y])
					parent[y]=x;

			}
		}
		if(siz!=n-1) printf("-1\n");
		else printf("%lld\n",ret);
	}
	return 0;
}
