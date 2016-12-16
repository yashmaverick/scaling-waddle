#include <stdio.h>
#include <stdlib.h>

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

#define pb(x)				push_back(x)
//typedef long long			LL;
//typedef pair<int, int>	PII;
//typedef vector<int>		VI;  
//typedef vector< PII >		VPII;

//FILE *fin = freopen("input.txt","r",stdin);
//FILE *fout = freopen("output.txt","w",stdout);

#define MOD					1000000007
#define MAX					1000000

#define all(a)				a.begin(),a.end()
#define allrev(a)			a.rbegin(),a.rend()			
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
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
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

//int gcd(int a, int b)		{return (a==0)?b:gcd(b%a,a);}

char ibuf[4096];
int input;

int readint(void);

int arr[1000000];

int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int t, n, i;
	long long ans,count;
	t = readint();
	while (t--)
	{
		n = readint();
		forall(i, 0, n)
			arr[i] = readint();
		qsort(arr, n, sizeof(int), cmpfunc);
		ans = 0;
		count = 1;
		forall(i,1,n)
		{
			if (arr[i] == arr[i - 1])
				count++;
			else
			{
				ans += ((count)*(count - 1))/2;
				count = 1;
			}
			//printf("%d %lld\n", i, count);
		}
		ans += ((count)*(count - 1)) /2;
		pl(ans);
		pew;
	}
	return 0;
}

int readint(void)
{
	int num;
	while ((input<4096) && (ibuf[input]<'0'))
		input++;
	if (input == 4096)
	{
		fread(ibuf, 1, 4096, stdin);
		input = 0;
		while ((input<4096) && (ibuf[input]<'0'))
			input++;
	}
	num = 0;
	while ((input<4096) && (ibuf[input] >= '0'))
		num = (num << 3) + (num << 1) + (ibuf[input++] - '0');
	if (input == 4096)
	{
		fread(ibuf, 1, 4096, stdin);
		input = 0;
		while ((input<4096) && (ibuf[input] >= '0'))
			num = (num << 3) + (num << 1) + (ibuf[input++] - '0');
	}
	return num;
}