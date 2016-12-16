#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,s;
	scanf("%d",&t);
	for(s=0;s<t;s++)
	{
		long long int n,k,i,j;
		long long int a[10005];
		scanf("%lld %lld",&n,&k);
		scanf("%lld",&a[0]);
		//		printf("%lld\n",k);
		//	printf("%lld\n",a[0]);
		long long int min=a[0];
		if(n==1)
		{
			printf("%lld\n",a[0]);
		}
		else
		{
			for(i=1;i<k;i++)
			{
				scanf("%lld",&a[i]);
				if(a[i]<min)
					min=a[i];
			}
			if(k!=0 && k!=n)
				printf("%lld ",min);
			for(i=k;i<n;i++)
			{
				scanf("%lld",&a[i]);
				if(min==a[i-k])
				{
					min=a[i-k+1];
					for(j=i-k+1;j<=i;j++)
					{
						if(min>a[j])
							min=a[j];
					}
					if(i!=n-1)
						printf("%lld ",min);
				}
				else if(min>a[i])
				{
					min=a[i];
					if(i!=n-1)
						printf("%lld ",a[i]);
				}
				else
				{
					if(i!=n-1)
						printf("%lld ",min);
				}
				/*	min=a[i-k+1];
					for(j=i-k+2;j<=i;j++)
					{
					if(min>a[j])
					min=a[j];
					}*/
			//	if(i!=n-1)
			//		printf("%lld ",min);
			}
			if(k!=0)
				printf("%lld\n",min);
		}
	}
	return 0;
}
