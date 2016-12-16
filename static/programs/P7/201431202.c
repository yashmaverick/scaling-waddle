#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long int a[n],i;
		long long int min=1000000000,b[1000001]={},temp,max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
			{
				
				min=a[i];
			}
		}
		long long int sum=0;
		for(i=0;i<n;i++)
		{
			temp=a[i]-min;
			++b[temp];
			if(temp>=max)
			{
				max=temp;
			}
		}
		for(i=0;i<=max;i++)
		{
			if(b[i]>1)
			{
				sum=sum+((b[i]*((b[i])-1) ) /2);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
