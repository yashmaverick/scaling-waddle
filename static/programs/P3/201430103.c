#include<stdio.h>
int main()
{
	int t;
	long long int i,N,j,k,min,max,x,arr[1000000];

	scanf("%d",&t);

	for(i=0;i<t;i++)
	{
		scanf("%lld",&N);

		for(j=0;j<N;j++)
			scanf("%lld",&arr[j]);

		max=-1;
		min=arr[i];

		for(k=0;k<N;k++)
		{
			if(arr[k]<=min)
				min=arr[k];

			x=arr[k]-min;

			if(x>max)
				max=x;
		}

		if(max>0)
			printf("%lld\n",max);

		else
			printf("0\n");
	}
return 0;
}
