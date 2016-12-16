#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
//#pragma pack(2)
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
struct bag
{
	int sum;
	int numberofweights;
	unsigned short index;
};
int bagcomp (const void * a, const void * b)
{
	int l = ((struct bag *)a)->sum;
	int m = ((struct bag *)b)->sum;
        if (l>m)
                return 1;
        else if (l<m)
                return -1;
	else if (l==m)
	{
		unsigned short l1 = ((struct bag *)a)->index;
		unsigned short m1 = ((struct bag *)b)->index;
		if (l1<m1)
			return -1;
		else
			return 1;
	}
}
int main()
{
	int n,mod,m,e,j;
	unsigned short i;
//	printf ("bag = %lu\n",sizeof(struct bag));
	sint(n);sint(mod);
	struct bag arr[n];
	int *weight[n];
	f0(i,n)
	{
		arr[i].sum=0;
		arr[i].index=i;
		sint(m);
		arr[i].numberofweights=m;
		weight[i] = (int *)malloc(m * sizeof(int));
		f0(j,m)
		{
			sint(e);
			arr[i].sum=(arr[i].sum+e)%mod;
			weight[i][j]=e;
//			pint(weight[i][j]);
		}
	}
	qsort(arr,n,sizeof(struct bag),bagcomp);
	f0(i,n)
	{
		pint(arr[i].sum);
		f0(j,arr[i].numberofweights){pint(weight[arr[i].index][j]);}
		printf("\n");
	}
	return 0;
}
