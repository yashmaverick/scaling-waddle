#include<stdio.h>
#include<stdlib.h>
int size;
typedef struct item{
	int u;
	int v;
	int w;
}item;
void insh(int v1,int v2,int cost,item a[])
{
	int i,tempu,tempv,tempw;
	size++;
	a[size].u=v1;
	a[size].v=v2;
	a[size].w=cost;
	for(i=size;i>1 && cost<a[i/2].w;i=i/2)
	{
		tempu=a[i].u;tempv=a[i].v;tempw=a[i].w;
		a[i].u=a[i/2].u; a[i].v=a[i/2].v; a[i].w=a[i/2].w;
		a[i/2].u=tempu; a[i/2].v=tempv; a[i/2].w=tempw;
	}
	return;
}
item delmin(item a[])
{
	int new,i,min,last,tempu,tempv;
	item this;
	this=a[1];
	min=a[1].w;
	tempu=a[size].u;
	tempv=a[size].v;
	last=a[size--].w;
	for(i=1;size>=2*i;i=new)
	{
		new=2*i;
		if(new!=size && a[new+1].w<a[new].w)
		{
			new++;
		}
		if(last>a[new].w)
		{
			a[i].u=a[new].u;
			a[i].v=a[new].v;
			a[i].w=a[new].w;
		}
		else
		{
			break;
		}
	}
	a[i].u=tempu;
	a[i].v=tempv;
	a[i].w=last;
	return this;
}
int f(int x,int parent[])
{
	if(parent[x]==x)
	{
		return x;
	}
	else
	{
		return f(parent[x],parent);
	}
}
int main()
{
	size=0;
	int i,cnt,j,k,n,m,t,ans;
	ans=0;cnt=0;int flag=0;
	item rec;
	int v1,v2,cost,p1,p2;
	scanf("%d %d",&n,&m);
	int parent[n+1];
	item a[m+1];
	for(i=0;i<=n;i++)
	{
		parent[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&v1,&v2,&cost);
		insh(v1,v2,cost,a);
	}
	while(cnt!=n-1)
	{
		if(size==0)
		{
			flag=1;
			break;
		}
		rec=delmin(a);
	//	printf("%d %d %d\n",rec.w,rec.u,rec.v);
		p1=f(rec.u,parent);
		p2=f(rec.v,parent);
	//	printf("%d %d\n",p1,p2);
		if(p1!=p2)
		{
			ans=ans+rec.w;
			cnt++;
			parent[p1]=rec.v;
		}
	}
	if(flag==0)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
