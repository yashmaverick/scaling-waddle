#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
int size;
struct pair{
	int a,i;
}null;
typedef struct pair pair;
struct stack{
	pair vl;
	struct stack* nxt;
};
typedef struct stack stack;
typedef long long LL;
stack* tp=NULL;
pair pop()
{       if(tp==NULL)
	return null;
	pair p=tp->vl;
	stack* st=tp;
	tp=tp->nxt;
	free(st);
	return p;
}
pair top()
{       if(tp==NULL)
	return null;
	return tp->vl;
}
void push(pair e)
{       stack* start=(stack*)malloc(sizeof(stack));
	start->vl=e;
	start->nxt=tp;
	tp=start;
}
int main()
{	pair a[100005];
	int n,i;int k;
 	sc(n);
	while(n)
	{tp=NULL;
	null.a=INT_MIN;
	null.i=-1;
	LL m=0;
	for(i=0;i<n;i++)
	{	sc(a[i].a);
		a[i].i=i;
		while(top().a>a[i].a)
		{	pair t=pop();
			LL tp=(LL)t.a*(i-t.i);
			a[i].i=t.i;
			if(tp>m)
				m=tp;
		}
		if(top().a<a[i].a)push(a[i]);
	}
	while(top().a>null.a)
	{	pair t=pop();
		LL tp=(LL)t.a * (n-t.i);
		if(tp>m)
			m=tp;
	}
	printf("%lld\n",m);
	sc(n);
	}
}


