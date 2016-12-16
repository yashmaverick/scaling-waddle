#include <stdio.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d\n",n)

int maxProfit(int A[],int n)
{
	int maxSoFar=0,sum=0,i;

	for(i=0;i<n;i++)
	{
		sum+=A[i];
		if(sum>maxSoFar)
			maxSoFar=sum;
		if (sum<0)
			sum=0;
	}
	return maxSoFar;
}

int main()
{
	int N,NA,A[100001],i,j,MS[100000];
	s(N);

	for(i=0;i<N;++i)
	{
		s(NA);
		for(j=0;j<NA;j++)
		{
			s(A[j]);
			if(j>0)
				MS[j-1]=(A[j]-A[j-1]);
		}
		p(maxProfit(MS,NA-1));
	}

	return 0;
}