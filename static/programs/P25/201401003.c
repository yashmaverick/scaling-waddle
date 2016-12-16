#include<stdio.h>
typedef struct Edges
{
	long long int src,dest,weight;
}Edges;
Edges edge[1000009];
long long int parent[100009],size[100009];
long long int compare(const void *a,const void *b)
{
	long long int p=((Edges *)a)->weight;
	long long int q=((Edges *)b)->weight;
	return p-q;
}
long long int find(long long int x)
{
	if(x==parent[x])
		return x;
	else
		return (parent[x]=find(parent[x]));
}
void join(long long int p,long long int q)
{
	if(size[p]<size[q])
	{
		parent[p]=q;
		size[q]+=size[p];
		size[p]=0;
	}
	else
	{
		parent[q]=p;
		size[p]+=size[q];
		size[q]=0;
	}
	return ;

}
int main()
{
	long long int n,m,i,u,v,w,par1,par2,ans=0,e;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&edge[i].src,&edge[i].dest,&edge[i].weight);
	}
	qsort((void *)edge,m,sizeof(Edges),compare);
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
//	for(i=0;i<m;i++)
//	{
//		printf("%lld %lld %lld\n",edge[i].src,edge[i].dest,edge[i].weight);
//	}
	e=0;
	i=0;
	while(i<m && e<n-1)
	{
		u=edge[i].src;
		v=edge[i].dest;
		w=edge[i].weight;
		par1=find(u);
		par2=find(v);
		if(par1!=par2)
		{
			join(par1,par2);
			ans+=w;
			e++;
		}
		i++;
	}
	if(e==n-1)
		printf("%lld\n",ans);
	else
		printf("-1\n");
	return 0;
}
