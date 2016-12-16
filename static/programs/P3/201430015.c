#include<stdio.h>
int main()
{
	int i,n,test;
	long long int a[100001],b[100001],max,sum;
	scanf("%d",&test);
	while(test)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		max=0;
		sum=0;
		for(i=1;i<n;i++)
		{
			b[i-1]=a[i]-a[i-1];
			sum+=b[i-1];
			if(sum<0)
			{
				sum=0;
			}
			if(sum>max)
			{
				max=sum;
			}
		}
		printf("%lld\n",max);
		test--;
	}		
	return 0;
}
