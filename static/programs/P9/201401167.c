#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%d",&n)
#define sc(n) scanf("%lld",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  LL t; sc(t); while(t--)
typedef long long LL;
struct pair{
	        LL a;LL i;
}null;
typedef struct pair pair;
static int cmp(const void* a, const void* b)
{	pair* a1 = (pair*)a;
	pair* b1 = (pair*)b;
	if(a1->a==b1->a)
		return (int)a1->i - b1->i;
	return (int)a1->a - b1->a;
}
int main()
{
	LL n,m[1002],mod;LL* ar[1002];
	pair b[1002];
	sc(n);sc(mod);
	LL i=-1,j;
	while(++i<n)
	{	sc(m[i]);
		b[i].i=i;
		b[i].a=0;
		ar[i]=(LL*)malloc(m[i]*sizeof(LL));
		j=-1;
		while(++j<m[i])
		{	sc(*(ar[i]+j));b[i].a+=*(LL*)(ar[i] + j);}
		b[i].a=b[i].a%mod;
	}
	qsort(b,n,sizeof(pair),cmp);
	i=-1;
	while(++i<n)
	{	printf("%lld\n",b[i].a);
		j=-1;
		while(++j<m[b[i].i])
			printf("%lld\n",*(ar[b[i].i]+j));
		printf("\n");
				
	}

return 0;
}
			

