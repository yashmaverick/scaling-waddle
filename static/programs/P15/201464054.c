#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
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
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)

int main()
{
	ll test,n,k,a[10002],forward[10002],backward[10002],partsindex[10002],i;	//partsindex array stores the index where a new part begins
	TEST
	{
		sll(n);	sll(k);
		f1(i,n){	sll(a[i]);	partsindex[i]=0;	}
		if (k==1)
		{
			f1(i,n-1){printf("%lld ",a[i]);}
			printf("%lld",a[n]);
			printf("\n");
			continue;
		}
		for(i=1;i<=n;i=i+k){	partsindex[i]=1;	partsindex[i-1]=-1;	}	// 1 means block starts, -1 means block ends
//		printf("Partsindex : \n");f1(i,n){printf("%lld ",partsindex[i]);}printf("\n");
		f1(i,n)
		{	
			if (partsindex[i]==1)
				forward[i]=a[i];
			else
			{
				if (a[i]>=forward[i-1])
					forward[i]=forward[i-1];
				else
					forward[i]=a[i];
			}
		}
//		printf("Forward : \n");f1(i,n){printf("%lld ",forward[i]);}printf("\n");
		f1r(i,n)
		{
			if (i==n)
				backward[i]=a[i];
			else
			{
				if (partsindex[i]==-1)
					backward[i]=a[i];
				else
				{
					if (a[i]>=backward[i+1])
						backward[i]=backward[i+1];
					else
						backward[i]=a[i];
				}
			}
		}
//		printf("Backward : \n");f1(i,n){printf("%lld ",backward[i]);}printf("\n");
		f1(i,(n-k))
		{
			if (backward[i]<=forward[i+k-1])
				printf("%lld ",backward[i]);
			else
				printf("%lld ",forward[i+k-1]);
		}
			if (backward[n-k+1]<=forward[n])
				printf("%lld",backward[n-k+1]);
			else
				printf("%lld",forward[n]);
		
		printf("\n");
	}
	return 0;
}
