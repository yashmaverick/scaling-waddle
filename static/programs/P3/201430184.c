#include<stdio.h>
int main()
{
        long long int count,test;
	scanf("%lld",&test);
	for(count=0;count<test;count++)
	{
		long long int size,i,j;
		scanf("%lld",&size);
		long long int a[size];
		long long int b[size];
		long long int c[size];
		for(i=0;i<size;i++)
		{
			scanf("%lld",&a[i]);
		}
		b[0]=a[0];
		c[size-1]=a[size-1];
		j=0;
		for(i=0;i<size-1;i++)
		{
			if(a[i+1]<b[i])
			{
				b[i+1]=a[i+1];
			}
			else if(b[i]<=a[i+1])
			{
				b[i+1]=b[i];
			}
		}
		for(i=size-2;i>=0;i--)
		{
			if(c[i+1]<a[i])
			{
				c[i]=a[i];
			}
			else if(a[i]<=c[i+1])
			{
				c[i]=c[i+1];
			}
		}
		for(i=0;i<size;i++)
		{
			if((c[i]-b[i])>j)
			{
				j=c[i]-b[i];
			}
		}
                printf("%lld\n",j);
	}
	return 0;
}
