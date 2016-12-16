#include<stdio.h>
#define MAX 100000
int main()
{
	long long int n,A[MAX],i;
	long long int max, min;
	long long int a;
	scanf("%lld", &a);
	while(a--)
	{
		scanf("%lld", &n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
		}
		max=0;
		min=1000000000;
		for(i=0;i<n;i++)
		{
			if(A[i]<min)
				min=A[i];
			if(max<(A[i]-min))
				max=A[i]-min;

		}
		printf("%lld\n", max);
	}
	return 0;
}
