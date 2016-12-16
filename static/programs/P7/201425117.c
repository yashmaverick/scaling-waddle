#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i;
		scanf("%d",&n);
		int A[n], min=10000000;
		for(i=0;i<n;i++)
		{	
			scanf("%d",&A[i]);
			if(A[i]<min)
				min=A[i];
		}
		long long int B[1000000];
		for(i=0;i<1000000;i++)
			B[i]=0;
		for(i=0;i<n;i++)
		{
			A[i]-=min;
			B[A[i]]++;
		}
		long long int sum=0;
		for(i=0;i<1000000;i++)
		{
			if(B[i]>1)
				sum+=(B[i])*(B[i]-1)/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
