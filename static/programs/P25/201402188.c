#include <stdio.h>
typedef struct node node;
struct node
{
	int u,v,wgt;
};

node a[1000000];
int p[1000000];

int compare (const void * a, const void * b)
{
        node *aa = (node *)a;
        node *bb = (node *)b;
        return aa->wgt - bb->wgt;
}

int parent(int x)
{
	if(p[x]==x)
		return x;
	p[x]=parent(p[x]);
	return p[x];
}

int main()
{
	int n,y,i,u1,v1,w1,t;
	scanf("%d%d",&n,&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&u1,&v1,&w1);
		a[i].u=u1;
		a[i].v=v1;
		a[i].wgt=w1;
	}
	qsort(a,t+1,sizeof(node),compare);
/*	for(i=1;i<=t;i++)
	{
		printf("w: %d,u: %d,v: %d\n",a[i].wgt,a[i].u,a[i].v);
	}
	printf("\n");*/
	for(i=1;i<=n;i++)
	{
		p[i]=i;
	}
	int aman=0,sum=0;
	for(i=1;i<=t;i++)
	{
		int x=parent(a[i].u);
		int y=parent(a[i].v);
	//	printf("x: %d,y: %d\n",x,y);
		if( x!= y)
		{
			aman++;
			sum=sum+a[i].wgt;
			p[x]=y;

		}
		
	}
	if(aman==n-1)
		printf("%d\n",sum );
	else
		printf("-1\n");
	return 0;
}
