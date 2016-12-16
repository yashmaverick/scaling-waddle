#include<stdio.h>
int main()
{
	long long int area,b,n,i,c,max=0,d,lp,rp;


	while(1)
	{
		lp=rp=0;	
		scanf("%lld",&n);
		long long int a[n];
		max=0;
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
			}
			for(i=0;i<n-1;i++)
			{
				if(i!=0&&a[i]<=a[i-1])
				{
					b=rp;
					while(b<n && a[b]>=a[i])
						b++;
				}
				else
				{
					b=i+1;
					while(b<n && a[b]>=a[i])
					{
						b++;
					}
				}
				rp=b;

				if(i!=0&&a[i]<=a[i-1])
				{
					d=lp;
					while(d>=0&&a[d]>=a[i])
						d--;
				}
				else
				{
					d=i-1;
					while(d>=0 && a[d]>=a[i]) 
					{
						d--;
					}
				}

				lp=d;
				//printf("%lld %lld\n",lp,rp);
				c=(b-d-1)*a[i];
				if(c>=max)
					max=c;

			}

			printf("%lld\n",max);
		}

	}
	return 0;
}
