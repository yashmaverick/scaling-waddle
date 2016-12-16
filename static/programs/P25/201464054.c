#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define pull(n); printf("%llu\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)
#define set(x,y) memset(x,y,sizeof(x));

struct edge {	ll a;	ll b;	ll wt;	}array[100005];
ll edgect;

void insertedge(ll u, ll v, ll w)
{
	array[edgect].a=u;
	array[edgect].b=v;
	array[edgect].wt=w;
	edgect++;
	return;
}
int comparator(const void *p, const void *q) 
{
	ll l = ((struct edge *)p)->wt;
	ll r = ((struct edge *)q)->wt;
	if (l<r)return -1;
	else if (l>r)return 1;
	else return 0;
}
int p[100005];
int size[100005];
int root (int x)
{
	if (p[x]==x)
		return x;
	else
	{
		p[x]=root(p[x]);
		return p[x];
	}
}
int edgepossible(struct edge x)
{
	if (root(x.a)==root(x.b))
		return 0;
	else
		return 1;
}
void merge(ll x, ll y)
{
	ll a1,a2;
	a1=root(x);
	a2=root(y);
	p[a1]=a2;
	return;
}
ll minimum( ll a, ll b ){	if (a<b)return a;	else return b;	}
ll maximum( ll a, ll b ){	if (a>b)return a;	else return b;	}
int main()
{
	ll u,v,w,i,j,m,n;
	sll(n);	sll(m);
	edgect=0;
	set(size,0);
	f1(i,n){	p[i]=i;		size[i]=1;	}
	f0(i,m){sll(u);	sll(v);	sll(w);	insertedge(u,v,w);}
	qsort(array,edgect,sizeof(struct edge),comparator);
//	f0(i,edgect){printf ("a = %lld %lld %lld\n",array[i].a,array[i].b,array[i].wt);}
	ll sum,count;
	sum=0;	count=0;
//	f1(j,n){printf ("%d ",p[j]);}printf ("\n");
	f0(i,edgect){
		if (count==(n-1))
			break;
		if(edgepossible(array[i])==1)
		{
			count++;
			ll t1,t2;
			t1=array[i].a;
			t2=array[i].b;
			merge(t1,t2);
	/*		if (size[root(t1)]<size[root(t2)])
			{
				size[root(t2)]+=size[root(t1)];
				p[t1]=root(t2);
			}
			else
			{
				size[root(t1)]+=size[root(t2)];
				p[t2]=root(t1);
			}*/
//			printf("%lld %lld\n",array[i].a,array[i].b);
			sum+=array[i].wt;
		}
//		printf("size");f1(j,n){printf("%d ",size[j]);}printf ("\n");
//		f1(j,n){printf ("%d ",p[j]);}printf ("\n");
	}
	if(count==(n-1)){pll(sum);}
	else {printf("-1\n");}
	return 0;
}
