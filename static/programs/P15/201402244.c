#include<stdio.h>
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--)
	{
		long long int n,k,i,j;
		scanf("%lld%lld",&n,&k);
		long long int h[n],q[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
		}
		long long int start=0;
		q[0]=h[0];
		for(i=1;i<k;i++)
		{
			q[i]=h[i];
			for(j=i-1;j>=start;j--)
			{
				if(q[i]<q[j])
					q[j]=q[i];
				else
					break;
			}
		}
		for(i=k;i<n;i++)
		{
			q[i]=h[i];
			start++;
			for(j=i-1;j>=start;j--)
			{
				if(q[i]<q[j])
					q[j]=q[i];
				else
					break;
			}

		}
		for(i=0;i<n-k;i++)
		{
		printf("%lld ",q[i]);
		}
		printf("%lld\n",q[n-k]);

	}
	return 0;
}
