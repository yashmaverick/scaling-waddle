#include<stdio.h>
int main()
{
	long long int t;
		scanf("%lld",&t);
	while(t--)
	{
		long long int a,i,min;
		scanf("%lld",&a);
		long long int b[a],c[1000001]={0},v=0;
		for(i=0;i<a;i++)
			scanf("%lld",&b[i]);
		min=b[0];
		for(i=1;i<a;i++)
		{
			if(min>b[i])
				min=b[i];
		}
		for(i=0;i<a;i++)
		{
			b[i]=b[i]-min;
		}
		for(i=0;i<a;i++)
		{
			c[b[i]]++;
		}
		for(i=0;i<1000000;i++)
		{
			v=v+(c[i]*(c[i]-1))/2;
		}
		printf("%lld\n",v);
	}
return 0;
}

