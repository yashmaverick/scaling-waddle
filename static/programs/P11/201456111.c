#include<stdio.h>
long long int a[1000000];
long long int fa=0;
long long int right,left;
void maxrect(long long int r,long long int s)
{


	long long int k,l,m,p,area,i,n;
	i=r;
	n=s;
	if(i==0)
	{
		for(k=1;k<=right;k++)
		{
			if(a[k]>=a[i])
				continue;
			else
			{
				right=(k-1);
				break;
			}

		}
		area=((right+1)*a[i]);
		if(area>fa)
		{
			fa=area;
		}
	}
	if(i!=0)
	{
		if(a[i]<a[i-1])
		{
			for(l=(right+1);l<=(n-1);l++)
			{
				if(a[l]>=a[i])
					continue;
				else
				{
					right=l-1;
					break;
				}
			}
			if(l==n)
				right=n-1;
			for(m=(left-1);m>=0;m--)
			{
				if(a[m]>=a[i])
					continue;
				else
				{
					left=m+1;
					break;
				}
			}
			if(m==-1)
				left=0;
			area=((right-left)+1)*a[i];
			if(area>fa)
				fa=area;
		}
		if(a[i]>a[i-1])
		{
			for(p=(i+1);p<=(n-1);p++)
			{
				if(a[p]>=a[i])
					continue;
				else
				{
					right=p-1;
					break;
				}

			}
			if(p==n)
				right=n-1;
			left=i;
			area=((right-left)+1)*a[i];
			if(area>fa)
				fa=area;

		}

	}

}
int main()
{
	long long int n,i;
	while(1)
	{
		fa=0;
		left=0;
		scanf("%lld",&n);
		right=(n-1);
		if(n==0)
			return 0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			maxrect(i,n);
		}
		printf("%lld\n",fa);
	}
	return 0;
}
