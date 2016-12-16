#include<stdio.h>
int main()
{
	long long int A[100000],min,diff;
	int t,i,j,n;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		diff=A[1]-A[0];
		min=A[0];
		for(i=0;i<n;i++)
		{
			if(A[i]-min>diff)
				diff=A[i]-min;
			if(A[i]<min)
				min=A[i];
		}
		printf("%lld\n",diff);
	}
	return 0;
}

