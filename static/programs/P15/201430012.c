#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stddef.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

#define si(a)				scanf("%d",&a)
#define sii(a,b)			scanf("%d%d",&a,&b)
#define siii(a,b,c)			scanf("%d%d%d",&a,&b,&c)
#define sl(a)				scanf("%lld",&a)
#define su(a)				scanf("%u",&a)
#define slu(a)				scanf("%llu",&a)
#define sf(a)				scanf("%f",&a)
#define sd(a)				scanf("%lf",&a)
#define ss(a)				scanf("%s",a)
#define pi(a)				printf("%d",a)
#define pii(a,b)			printf("%d%d",a,b)
#define piii(a,b,c)			printf("%d%d%d",a,b,c)
#define pl(a)				printf("%lld",a)
#define pew					printf("\n")	

#define LL				long long 
#define UI				unsigned int
#define ULL				unsigned long long
#define MOD					1000000007
#define MAX					1000000
#define forall(i,a,b)		for(i=a; i<b; i++)
#define forrev(i,a,b)		for(i=a; i>=b; i--)
#define w(t)				int t;si(t);while(t--)
#define IN(i,l,r) (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)

#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define bit(x,i)					(x&(1<<i))  //select the bit of position i of x
#define lowbit(x)					((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n)					asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x

/*long long fast_exp(int base, int exp)
{
long long res = 1;
while (exp>0)
{
if (exp&1==1)
res = (res*base) % MOD;
base = (base*base) % MOD;
exp /= 2;
}
return res%MOD;
}*/

//int gcd(int a,int b)	{return ((a==0)?b:gcd(b%a,a));}
typedef struct pair
{
	int first;
	int second;
}pair;


int front, itr;
int arr[10000];
pair dq[MAX];

void compute(int n, int k)
{
	int i, j;
	for (i = 0; i < k; i++)
	{
		while ((itr >= front) && (arr[i] <= dq[itr].second))
			--itr;
		++itr;
		dq[itr].first = i;
		dq[itr].second = arr[i];
	//	for (j = front; j <= itr; j++)
	//		printf("%d ", dq[j].second);
	
	}
	printf("%d", dq[front].second);
	if (k != n)
		printf(" ");
	for (i = k; i < n; i++)
	{
		while ((itr >= front) && dq[front].first <= (i - k))
			++front;
		while ((itr >= front) && (arr[i] <= dq[itr].second))
			--itr;
		++itr;
		dq[itr].first = i;
		dq[itr].second = arr[i];
		
		printf("%d", dq[front].second);
		//	for (j = front; j <= itr; j++)
		//		printf("%d ", dq[j].second);
		if (i != n - 1)
			printf(" ");
	}
	printf("\n");
}

int main()
{
	int n, k, i;
	w(t)
	{
		sii(n, k);
		forall(i, 0, n)
			si(arr[i]);
		front = 0;
		itr = -1;
		compute(n, k);
	}
	return 0;
}
