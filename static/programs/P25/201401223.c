#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int p[100000];
long long int tw;
struct node
{
	int s;
	int d;
	int w;
}a[100000];
int cmpfunc (const void * a, const void * b)
{
	struct node* c=(struct node*)a;
	struct node* d=(struct node*)b;
	return c->w-d->w;
}
int parent(int vertex)
{
	if(p[vertex]==0)
		return vertex;
	return p[vertex] = parent(p[vertex]);
}
int main()
{
	int n,m,i,j,k,pa,q;
	int te = 0,edge=0,start,desti,weight;
	struct node temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a[i].s,&a[i].d,&a[i].w);
	}
	qsort(a,m,sizeof(struct node),cmpfunc);
	//	for(i=0;i<m;i++)
	//	{
	//		printf("%d\n",a[i].w);
	//	}
	for(i=0;i<n;i++)
	{
		p[i]=0;
	}
	while(te < n -1)
	{
		if(edge==m)
		{
			printf("-1\n");
			return;
		
		}
		temp = a[edge];
		start = temp.s;
		desti = temp.d;
		weight=temp.w;
		pa = parent(start);
		q = parent(desti);
		edge++;
		if(pa!=q)
		{
			tw+= weight;
			p[pa]=q;
			te++;
		}
	}
	printf("%lld\n",tw);
	return 0;
}


