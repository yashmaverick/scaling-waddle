#include<stdio.h>
int main()
{
	long long int  A[1000000],a,b,c,size,i,max,min,sum;
	long long int n;
	scanf("%lld",&n);
	while(n--)
	{
		max=-10000000;
		min=10000000;
		sum=0;
		scanf("%lld",&size);
		for(i=0;i<size;i++)
		{
			scanf("%lld",&A[i]);
			if(A[i]>max)
				max=A[i];
			if(A[i]<min)
				min=A[i];
		}
		long long int B[(max-min)+1];
		for(i=0;i<=max-min;i++)
			B[i]=0;
		for(i=0;i<size;i++)
		{
			B[max-A[i]]=B[max-A[i]]+1;	
		}
		for(i=0;i<=max-min;i++)
		{
			if(B[i]>1)
				sum=sum+((B[i]*(B[i]-1))/2);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
