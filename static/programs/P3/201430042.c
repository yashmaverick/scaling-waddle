#include<stdio.h>
int main()
{
	int test;
	long long int a[100000];
	long long int min,n,profit;
	int i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		min=a[0];
		profit=0;
		for(i=1;i<n;i++)
		{
			if(a[i]<min)
			{
				//printf("value of a[%d]= %lld value of min=%lld\n",i,a[i],min);
				min=a[i];
				//printf("min value changed to %lld\n",min);
			}
			if((a[i]-min)>profit)
			{
				profit=(a[i]-min);
				//printf("profit is%lld\n",profit);
			}
		}
		printf("%lld\n",profit);
	}
	return 0;
}
		
