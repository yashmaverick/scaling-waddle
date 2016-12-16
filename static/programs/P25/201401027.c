#include<stdio.h>
#include<stdlib.h>
#define Max 100003
long long int size=0,par[Max],rank[Max];
typedef struct heap
{
	long long int a,b,d;
}heap;
heap min[Max];
void swap(long long int p,long long int c)
{
	heap t=min[p];
	min[p]=min[c];
	min[c]=t;
}
void insmin(long long int c)
{
	long long int p=c/2;
	while(p>0 && min[p].d>min[c].d)
	{
		swap(p,c);
		c=p;
		p=c/2;
	}
}
void heapify(long long int p)
{
	long long int c=2*p;
	while(c<=size)
	{
		if(c+1<=size && min[c].d>min[c+1].d)
			c++;
		if(min[p].d>min[c].d)
			swap(p,c);
		else
			break;
		p=c;
		c=2*p;
	}
}
long long int find(long long int i)
{
	if(par[i]==i)
		return i;
	return par[i]=find(par[i]);
}
int main()
{
	long long int v,e,i,cnt,a1,b1,sdis;
	size=cnt=sdis=0;
	scanf("%lld%lld",&v,&e);
	for(i=0;i<e;i++)
	{
		size++;
		scanf("%lld%lld%lld",&min[size].a,&min[size].b,&min[size].d);
		insmin(size);
	}
	for(i=1;i<=v;i++)
	{
		par[i]=i;
		rank[i]=1;
	}
	while(size!=0 && cnt!=v-1)
	{
		a1=find(min[1].a),b1=find(min[1].b);
		if(a1!=b1)
		{
			cnt++;
			a1=find(a1),b1=find(b1);
			if(rank[a1]<=rank[b1])
			{
				rank[b1]+=rank[a1];
				par[a1]=par[b1];
			}
			else
			{
				rank[a1]+=rank[b1];
				par[b1]=par[a1];
			}
			//par[find(a1)]=find(b1);
			sdis+=min[1].d;
			swap(1,size--);
			heapify(1);
			continue;
		}
		swap(1,size--);
		heapify(1);
	}
	if(cnt!=v-1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",sdis);
	return 0;
}

