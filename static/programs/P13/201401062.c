#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

#define MAXN 100002
int depth[MAXN];
int arr[MAXN];
int stack[MAXN];
int left[MAXN];
int head=-1;
int ans;
typedef struct pair{
	int first;
	int second;
}pair;
void push(int elem)
{
	stack[++head]=elem;
}

void pop()
{
	head--;
}
int top()
{
	return stack[head];
}
int size()
{
	return 1+head;
}
void clear()
{
	head=-1;
}

int solve(int L,int R,int d)
{
	//printf("%d %d %d\n",L,R,d);
	if(L>R)
		return 0;
	//printf("%d %d %d\n",L,R,d);
	if(L==R)
	{
		depth[L]=d;
		return L;
	}
	int n = R;
	depth[n]=d;
	R = R-1;
	if(L<=left[n] && left[n]<=R)
	{
		int l = solve(L,left[n],d+1);
		int r = solve(left[n]+1,R,d+1);
		if(depth[l]<depth[r])
			return r;
		else if(depth[l]>depth[r])
			return l;
		else
			return min(l,r);
	}
	else
		return solve(L,R,d+1);
}


int main()
{
	int t;
	int i;
	din(t);
	while(t--)
	{
		int n;
		//int ans=-1;
		din(n);
		arr[0]=-INF;
		depth[0]=-1;
		clear();
		push(0);
		for(i=1;i<=n;i++)
		{
			din(arr[i]);
			while(arr[i]<arr[top()])
				pop();
			left[i]=top();
			push(i);
			//printf("%d %d\n",arr[i],left[i]);
		}
		int ans=solve(1,n,0);
		//for(i=1;i<=n;i++)
		//	printf("%d %d\n",arr[i],depth[i]);
		printf("%d %d\n",arr[ans],depth[ans]);

	}
	return 0;
}
