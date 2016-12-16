#include<stdio.h>
#define MAX 100009
int main()
{
	long long int tc,profit=0,max,i,k,n;
	long long int A[MAX];
	scanf("%lld",&tc);
	while(tc--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		k=n-2;
		max=A[n-1],profit=0;
		while(k>=0)
		{
			if(max-A[k]>=profit)
				profit=max-A[k];
			if(A[k]>max)
				max=A[k];
			k--;
		}
		printf("%lld\n",profit);
	}
	return 0;
}
