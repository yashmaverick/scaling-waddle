#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		long long int  a[1000007],k;
		 long long int i,j,min,max;
		max=-10000000;
		min=10000000;
		scanf("%lld",&k);
		for(i=0;i<k;i++)
		{
			scanf("%lld",&a[i]);
			if(min>a[i])
				min=a[i];
			if(max<a[i])
				max=a[i];
		}
		 long long int n=(max-min+1);
	//	printf("max=%d\n",max);
	//	printf("min=%d",min);
	long long int b[1000007];
	long long int c=0,p;
	for(i=0;i<n;i++)
		b[i]=0;
	for(i=0;i<k;i++)
	{
		b[max-a[i]]=b[max-a[i]]+1;
	}
	for(i=0;i<max-min+1;i++)
	{
		p=b[i];
		if(p>1)
		c=c+(p*(p-1))/2;
	}
	printf("%lld\n",c);
	}
	return 0;
}

