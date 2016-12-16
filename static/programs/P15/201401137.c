#include<stdio.h>

long long int start,poi;

void push(long long int b[],long long int value)
{
	b[poi]=value;
	poi++;
}

void pop(long long int a[])
{
	poi--;
}

int main()
{
	int t,h;
	scanf("%lld",&t);
	for(h=0;h<t;h++)
	{
		long long int n,i,k,j;
		start=0,poi=0;
		scanf("%lld%lld",&n,&k);
		long long int a[n],b[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(poi==start)
				push(b,i);
			else
			{
				while(a[b[poi-1]]>a[i])
				{
					pop(b);
					if(poi<=start)
						break;
				}
				push(b,i);
			}
			while(1)
			{
				if(b[start]<=i-k)
				{
					start++;
				}
				else
					break;
			}
			if(i>=k-1 && i!=n-1)
			{
				printf("%lld ",a[b[start]]);
			}
			if(i==n-1)
				printf("%lld\n",a[b[start]]);
		}
	}
	return 0;
}
			
