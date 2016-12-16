#include<stdio.h>
#include<stdlib.h>
typedef struct vertex{
	long long num;
	long long dist;
}vertex;
vertex *v[400005];
long long size[400005],list[400005][3];
long long mark[400005];
long long heap[400005],heappos[400005];
long long dist[400005];
long long parents[400005],ans[1000005];
int main()
{
	int t=1;
	while(t--)
	{
		long long n,m,j,i;
		for(i=1;i<400005;i++)
		{
			v[i]=NULL;
			size[i]=mark[i]=heap[i]=heappos[i]=dist[i]=parents[i]=ans[i]=0;
		}
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld %lld %lld",&list[i][0],&list[i][1],&list[i][2]);
			size[list[i][0]]++;
		}
		for(i=1;i<=n;i++)
		{
			v[i]=(vertex *)malloc(size[i]*(sizeof(vertex)));
			size[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			v[list[i][0]][size[list[i][0]]].num=list[i][1];
			v[list[i][0]][size[list[i][0]]++].dist=list[i][2];
		}
		long long fnode=1,enode;
		scanf("%lld %lld",&fnode,&enode);
		parents[fnode]=-1;
		for(i=1;i<=n;i++)
			dist[i]=200000000000000000;
		dist[fnode]=0;
		long long heapsize=1;
		heap[1]=fnode;
		mark[fnode]=1;
		heappos[fnode]=1;
		while(heapsize!=0)
		{
			long long top=heap[1];
			for(i=0;i<size[top];i++)
			{
				if(mark[v[top][i].num]==0)
				{
					mark[v[top][i].num]=1;
					heapsize++;
					heap[heapsize]=v[top][i].num;
					heappos[v[top][i].num]=heapsize;
					long long p=heapsize;
					while(p/2>=1&&dist[heap[p/2]]>dist[heap[p]])
					{
						long long temp=heap[p];
						heap[p]=heap[p/2];
						heap[p/2]=temp;
						heappos[heap[p]]=p;
						heappos[heap[p/2]]=p/2;
						p=p/2;
					}
				}
				if(dist[top]+v[top][i].dist<dist[v[top][i].num])
				{
					dist[v[top][i].num]=dist[top]+v[top][i].dist;
					parents[v[top][i].num]=top;
					long long p=heappos[v[top][i].num];
					while(p/2>=1&&dist[heap[p/2]]>dist[heap[p]])
					{
						long long temp=heap[p];
						heap[p]=heap[p/2];
						heap[p/2]=temp;
						heappos[heap[p]]=p;
						heappos[heap[p/2]]=p/2;
						p=p/2;
					}
				}
			}
			heap[1]=heap[heapsize];
			heappos[heap[1]]=1;
			heapsize--;
			long long p=1;
			while((2*p<=heapsize&&dist[heap[2*p]]<dist[heap[p]])||(2*p+1<=heapsize&&dist[heap[2*p+1]]<dist[heap[p]]))
			{
				long long temp=heap[p];
				if(2*p+1>heapsize||dist[heap[2*p]]<dist[heap[2*p+1]])
				{
					heap[p]=heap[2*p];
					heap[2*p]=temp;
					heappos[heap[p]]=p;
					heappos[heap[p*2]]=p*2;
					p=p*2;
				}
				else
				{
					heap[p]=heap[2*p+1];
					heap[2*p+1]=temp;
					p=p*2+1;
					heappos[heap[p]]=p;
					heappos[heap[p*2+1]]=p*2+1;
				}
			}
		}
		if(mark[enode]==0)
			printf("NO\n");
		else
			printf("%lld\n",dist[enode]);
	}
	return 0;
}
