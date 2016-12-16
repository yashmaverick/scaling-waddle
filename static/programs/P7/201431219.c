#include <stdio.h>
long long int A[1000001];
long long int B[1000001];
int main()
{
	int test;
	scanf("%d", &test);
		long long int i,j,k,l,n,m;
		long long int sum;
	while(test--)
	{
		sum=0;
		scanf("%lld", &n);
		scanf("%lld", &A[0]);
		long long int min,max;
		max=min=A[0];
		for(i=1;i<n;i++)
		{
			scanf("%lld", &A[i]);
			if(A[i]<min)
			{
				min=A[i];
			}
			if(A[i]>max)
				max=A[i];
		}
		for(i=0;i<=(max-min);i++)
			B[i]=0;		
		for(i=0;i<n;i++)
		{
				B[A[i]-min]++;
		}
		for(i=0;i<=(max-min);i++){
			sum+=(B[i]*(B[i]-1))/2;
		}
		printf("%lld\n",sum);

	}
return 0;
}
