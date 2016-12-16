#include<stdio.h>
#define LIMIT 1000000001
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int A[100000],n,i,max=0,min=LIMIT,dif;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);	
			if(min>A[i])		//checking for min 
				min=A[i];
			dif=A[i]-min;
			if(max<dif)		//comparing the difference with previously stored max value
				max=dif;
		}
		printf("%lld\n",max);
	}
	return 0;
}
			
