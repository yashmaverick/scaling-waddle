#include<stdio.h>
#include<stdlib.h>
long long int func(long long int *b)
{
	long long int i;
	long long int sum=0;
	for(i=0;i<1000002;i++)
	{
		if(b[i]==0||b[i]==1)
		{
		}
		else
		{
			sum+=b[i]*(b[i]-1)/2;
		}

	}
	return sum;
}
int main()
{
	int t;
	long long int *a,min,count,*b,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&count);
		a=(long long int *)malloc(sizeof(long long int)*count);
		b=(long long int *)malloc(sizeof(long long int)*1000002);
		for(i=0;i<count;i++)
		{
			scanf("%lld",&a[i]);
		}
		min=a[0];
		for(i=0;i<count;i++)
		{
			if(a[i]<min)
				min=a[i];

		}
		for(i=0;i<count;i++)
		{
			a[i]-=min;
		}
		for(i=0;i<1000002;i++)
			b[i]=0;
		for(i=0;i<count;i++)
			b[a[i]]++;
		printf("%lld\n",func(b));
	}
	return 0;
}
