#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
int size;
struct stack{
	int vl;
	struct stack* nxt;
};
typedef struct stack stack;
typedef long long LL;
stack* tp=NULL;
int pop()
{	if(tp==NULL)
	return INT_MIN;
	int p=tp->vl;
	stack* st=tp;
	tp=tp->nxt;
	free(st);
	return p;
}
int top()
{	if(tp==NULL)
	return INT_MIN;
	return tp->vl;
}
void push(int e)
{	stack* start=(stack*)malloc(sizeof(stack));
	start->vl=e;
	start->nxt=tp;
	tp=start;
}
int topk(int k)
{       stack* st=tp;
	while(st!=NULL && k>0)
	{k--;st=st->nxt;}
	if(k>0)
		return 0;
	else
		return st->vl;
}
int main()
{	
	int i,n,ar[500005],br[500005],cr[500005];
	sc(n);ar[0]=INT_MAX;
	push(0);cr[0]=-1;
while(n)	
	{
	LL m=0,mx=1;
	
	for(i=1;i<n+1;i++)
	{	sc(ar[i]);
		int j=0,k=0;
		while(ar[top()]<=ar[i])
		{mx=pop();j++;}
		br[i]=top();
		push(i);
//		printf("%d\n",i);
	}
//	printf("ok\n");
	while(top()!=0)
		pop();
	for(i=1;i<n+1;i++)
	{	while(ar[top()]<ar[i])
		pop();
		cr[i]=top();
		push(i);
	}
	while(top()!=0)
		pop();
//	printf("okk\n");
	for(i=2;i<n+1;i++)
	{	int v=i-1;
		m+=i-1;
		while(v>=br[i] && v>0)
		{v=cr[v];
			m--;
		}
//		printf("%d\n",i);
	}
	printf("%lld\n",m);
	sc(n);
	}
return 0;
}

