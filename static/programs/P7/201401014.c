#include<stdio.h>
long long int A[1000000],B[1000000];
int main()
{
	long long int n,i,t,max,min,pairs;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		pairs=0;
//		B[1000000]= {0} ;
		
		max=-10000000;
		min=10000000;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
			if(min>A[i])
				min=A[i];
			if(max<A[i])
				max=A[i];
		}
		for(i=0;i<n;i++)
			B[A[i]-min]++;
		for(i=0;i<1000000;i++)
		{
			if(B[i]==0 )
				continue;
			if(B[i]==1)
			{
				B[i]=0;
				continue;
			}
			else
				pairs+=((B[i]*(B[i]-1))/2);
			B[i]=0;
		}
		printf("%lld\n",pairs);
		}
return 0;
	}






