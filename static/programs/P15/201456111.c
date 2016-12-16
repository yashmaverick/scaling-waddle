#include<stdio.h>
int main()
{
	long long int t,l,k,n,i,m,s,p,start;
	long long int a[100000];
	long long int b[100000];
	scanf("%lld",&t);
	for(l=0;l<t;l++)
	{
		scanf("%lld",&n);
		scanf("%lld",&k);
		for(p=0;p<n;p++)
		{
			scanf("%lld",&a[p]);
		}
		start=0;
		for(m=0;m<n;m++)
		{
			if(m>k-1)
			{
				start++;
			}
			i=m;
			b[m]=a[m];
			i--;
			while(i>=start)
			{
				if(b[i]>b[i+1])
				{
					b[i]=b[i+1];
				}
				else
				{
					if(b[i]<=b[i+1])
					break;
				}
				i--;
		        }
		}


		for(s=0;s<(n-k+1);s++)
		{
			if(s==n-k)
			printf("%lld\n",b[s]);
			else
			printf("%lld ",b[s]);
		}

	}
	return 0;
}
