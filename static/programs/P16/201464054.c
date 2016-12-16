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


int main()
{
	ll test,q,i,power2[40],edges;	// power2[i]=2^i
	power2[0]=1;
	f1(i,40){	power2[i]=2*power2[i-1];	/*printf ("%lld ",power2[i]);*/}/*printf("\n");*/
	TEST
	{
		sll(q);
		if (q==1)
		{
			printf("0\n");
			continue;
		}
		i=0;	edges=0;
		while (1)
		{
			if ( q>=power2[i] && q<power2[i+1] && i<32 )
				break;
			else
			{
				i++;
				edges+=2;
			}
		}
		if ( q < ((power2[i]+power2[i+1])/2) )
			edges--;
//		printf("i = %lld edges = %lld\n",i,edges);
		pll(edges);
	}
	return 0;
}
