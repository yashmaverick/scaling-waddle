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

#define MAXN 100001
int stack[MAXN];
int head=-1;
int left[MAXN];
int right[MAXN];
int arr[MAXN];
void push(int n)
{
	stack[++head]=n;
}
void pop()
{
	head--;
}
int front()
{
	return stack[head];
}

int main()
{
	int n;
	int i;
	while(1)
	{
		din(n);
		if(!n)
			break;
		for(i=1;i<=n;i++)
			din(arr[i]);
		arr[0] = INT_MIN;
		push(0);
		for(i=1;i<=n;i++)
		{
			while(arr[front()]>=arr[i])
				pop();
			left[i] = front();
			push(i);
		}
		while(front()!=0)
			pop();
		pop();
		
		arr[n+1]=INT_MIN;
		push(n+1);
		for(i=n;i>=1;i--)
		{
			while(arr[front()]>=arr[i])
				pop();
			right[i] = front();
			push(i);
		}


		long long int ans = 0;
		for(i=1;i<=n;i++)
		{
			ans = max(ans,(long long int)arr[i]*(long long int)(right[i]-left[i]-1));
		}
		lldout(ans);
	}
	return 0;
}
