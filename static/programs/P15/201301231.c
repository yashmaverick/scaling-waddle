#include <stdio.h>

int main()
{
	long long int t,T,n,i,j,k,a[10000],min,prev,s[10000];

	scanf("%lld",&T);

	for(t=1;t<=T;t++)
	{
		scanf("%lld %lld",&n,&k);

		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			//s[i]=0;
		}

		min=a[n-1];

		for(i=n-k;i<n;i++)
		{
			if(min > a[i])
				min=a[i];
		}

		s[n-k]=min;

		for(i=n-k-1;i>=0;i--)
		{
			if(a[i+k] != s[i+1])
			{
				if(s[i+1] < a[i])
					s[i]=s[i+1];
				else
					s[i]=a[i];
			}
			else
			{
				min=a[i];

				for(j=1;j<k;j++)
				{
					if(min > a[j+i])
						min=a[j+i];
				}
				s[i]=min;
			}
		}

		for(i=0;i<n-k;i++)
			printf("%lld ",s[i]);
		printf("%lld\n",s[n-k]);

	}

	return 0;
}
