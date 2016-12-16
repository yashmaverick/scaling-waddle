#include<stdio.h>
long long int start;
int main()
{
	long long int a[10001],b[10001],c[10001],n,k,t,i,j,min,minindex,x,y,l;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		start=0;l=0;
		for(i=0;i<n-k+1;i++,start++)
		{
			if(start == 0)
			{
				x=a[0];y=0;
				for(j=start;j<k+start;j++)
				{
					if(a[j] <= x)
					{
						x=a[j];
						y=j;
					}
				}
				min=x;c[l]=min;l++;minindex=y;
				continue;
			}
			else
			{
				j=i+k-1;
				if(min >= a[j])
                                {
                                       min=a[j];c[l]=min;l++;minindex=j;
                                }
				else if(minindex == start-1)
				{
					x=a[start];y=start;
					for(j=start;j<k+start;j++)
					{
						if(a[j] <= x)
						{
							x=a[j];
							y=j;
						}
					}
					min=x;c[l]=min;l++;minindex=y;						
				}
				else
				{
						c[l]=c[l-1];l++;
				}
			}
		}
		for(i=0;i<l;i++)
		{
			if(i != l-1)
				printf("%lld ",c[i]);
			else
				printf("%lld\n",c[l-1]);
		}
	}
	return 0;
}
