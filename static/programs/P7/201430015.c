#include<stdio.h>
long long int test;
long long int i,j,n,count;
long long int a[1000000],max;
int main()
{	
	scanf("%lld",&test);
	while(test)
	{
		long long int flag[1000001]={0};
		test--;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(i==0)
			{
				max=a[i];
			}
			else if(a[i]>max)
			{
				max=a[i];
			}
		}
		for(i=0;i<n;i++)
		{
			a[i]=max-a[i];
			flag[a[i]]++;			
		}
		count=0;
		for(i=0;i<=1000000;i++)
		{
			count+=(flag[i]*(flag[i]-1))/2;
		}
		printf("%lld\n",count);
	}
	return 0;
}

