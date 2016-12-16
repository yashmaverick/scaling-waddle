#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
typedef struct data{
	int w;
	int u;
	int v;
}data;
typedef struct dsu{
	int parent;
	int rank;
}dsu;
data node[1000009];
dsu set[1000009];
int main()
{
	int n,m,i,x,y,count=0;
	scanf("%d%d",&n,&m);
	node[0].w=0;
	node[0].u=0;
	node[0].v=0;
	for(i=1;i<=m;i++)
	{
		set[i].parent=i;
		set[i].rank=1;
		scanf("%d%d%d",&node[i].u,&node[i].v,&node[i].w);
	}
	qsort(node, m+1, sizeof(data), cmpfunc);
	long long int sum=0;
	for(i=1;i<=m;i++)
	{
		x=node[i].u;
		y=node[i].v;
		while(x!=set[x].parent)
			x=set[x].parent;
		while(y!=set[y].parent)
			y=set[y].parent;
		if(x!=y)
		{
			count++;
			sum+=node[i].w;
		}
		if(set[x].rank==set[y].rank)
		{
			set[x].rank=set[x].rank+1;
			set[y].parent=x;
			set[y].rank=0;
		}
		else if(set[x].rank>set[y].rank)
		{
			set[y].parent=x;
			set[y].rank=0;
		}
		else
		{
			set[x].parent=y;
			set[x].rank=0;
		}
	}
	if(count==n-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
