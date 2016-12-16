#include<stdio.h>
int main()
{
	long long int n,max1,count,i,j,whole_max=0;
	scanf("%lld",&n);
	while(n!=0)
	{
		count=0;
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(i==0)
				whole_max=a[i];
			else
			{
					if(whole_max<a[i])
						whole_max=a[i];
			}
		}
	//	printf("%lld ",whole_max);
		for(i=0;i<=n-2;i++)
		{
	//		if(a[i]==whole_max)
	//			count+=n-i-2;
		//	else
		//	{
				max1=a[i+1];
				if(a[i+1]<=a[i])
				{
				
					for(j=i+2;j<n;j++)
					{
						if(a[j]>a[i])
						{
							count++;
							break;
						}
						else if(a[j]>=max1)
						{
							count++;
							max1=a[j];

						}
					}
				}
		//	}
		}
		printf("%lld\n",(n*(n-1))/2-(n-1)-count);
		scanf("%lld",&n);
	}
	return 0;
}
