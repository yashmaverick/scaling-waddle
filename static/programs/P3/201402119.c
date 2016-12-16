#include<stdio.h>

int main()
{
	long long int d[100000],a[100000],b[100000],n,c[100000],i,j,k,t,l=0;
	scanf("%lld",&t);
	while(t--)
	{
		l=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			d[i]=a[i];
		}
		for(i=0;i<n;i++)
		{
			j=n-i-1;
			if(i < n-1)
			{
				if(a[i] > a[i+1])
				{
					b[i] = a[i];
				}
				else
				{
					b[i] = a[i];
					a[i+1] = a[i];
				}
			}
			if(j>0)
			{
				if(d[j-1] < d[j])
				{
					c[j]=d[j];
					d[j-1]=d[j];
				}
				else
				{
					c[j]=d[j];
				}
			}
		}	
		b[n-1]=a[n-1];
		c[0]=d[0];
		for(i=0;i<n;i++)
		{
			a[i]=c[i] - b[i];
			k=a[i];
			if(k>=l)
			{
				l=k;
			}
		}
		printf("%lld\n",l);
	}
	return 0;
}
	

		

