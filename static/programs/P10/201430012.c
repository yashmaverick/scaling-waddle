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

typedef struct buff
{
	char s[105];
}buff;

int main()
{
	int size, itr, n, start = 0, i;
	char temp[4];
	buff *arr;
	si(size);
	arr = (buff *)malloc(sizeof(buff)*size);
	itr = 0;
	while (1)
	{
		ss(temp);
		if (temp[0] == 'Q')
			break;
		else if (temp[0] == 'A')
		{
			si(n);
			while (n--)
			{
				ss(arr[(start+itr)%size].s);
				if (itr != size)
					++itr;
				else
					start = (start + 1) % size;
			}
		}
		else if (temp[0] == 'R')
		{
			si(n);
			itr -= n;
			start = (start + n) % size;
		}
		else if (temp[0] == 'L')
		{
			forall(i, 0, itr)
				printf("%s\n", arr[(start + i) % size].s);
		}
	}
	return 0;
}