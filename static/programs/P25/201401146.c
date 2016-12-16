#include<stdio.h>
int par[100001]={0};
int U[1000000],V[1000000],edge[1000000];
void Qsort(int *a,int sta,int end)
{
	if(sta>=end)
		return;
	int i,t,w,u,v;
	w=sta;
	for(i=sta;i<=end;i++)
	{
		if(a[i]<=a[end])
		{
			t=a[w];
			a[w]=a[i];
			a[i]=t;
			u=U[w];
			U[w]=U[i];
			U[i]=u;
			v=V[w];
			V[w]=V[i];
			V[i]=v;
			w++;
		}
	}
	Qsort(a,sta,w-2);
	Qsort(a,w,end);
	return;
}
int get_par(int x)
{
	if(!par[x] || par[x]==x)
	{
		par[x]=x;
		return x;
	}
	par[x]=get_par(par[x]);
	return par[x];
}
int check_comp(int i)
{
	int par_u,par_v;
	par_u=get_par(U[i]);
	par_v=get_par(V[i]);
	if(par_u==par_v)
		return 0;
	else
		return 1;
}
void merge(int i,int n)
{
	int par_u,par_v,x;
	par_u=get_par(U[i]);
	par_v=get_par(V[i]);
	if(par_u<par_v)
	{
		x=1;
		while(x<=n)
		{
			if(par[x]==par_v)
				par[x]=par_u;
			x++;
		}
	}
	else
	{
		x=1;
		while(x<=n)
		{
			if(par[x]==par_u)
				par[x]=par_v;
			x++;
		}
	}
	return;
}
long long int krus(int n,int m)
{
	int i,sides=0,k;
	long long int d=0;
	for(i=0;i<m;i++)
	{
		if(check_comp(i))
		{
			d+=edge[i];
			sides++;
			merge(i,n);
		}
	}
	if(sides==n-1)
		return d;
	else
		return -1;
}
int main()
{
	int n,m,i;
	long long int x;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&U[i],&V[i],&edge[i]);
	}
	Qsort(edge,0,m-1);
	x=krus(n,m);
	printf("%lld\n",x);
	return 0;
}
