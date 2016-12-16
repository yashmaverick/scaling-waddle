#include<stdio.h>
int main()
{
	int t,x;
	long long int n;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		scanf("%lld",&n);
		long long int a[n-1],y,max=0,min=0;
		for(y=0;y<(n);y++)
		{
			scanf("%lld",&a[y]);
			if(a[y]>max)
				max=a[y];
			if(a[y]<min)
				min=a[y];
			//printf("max is %lld min is %lld\n",max,min);
		}
		long long int z;
		z=(max-min+1);
		long long int b[z];
		for(y=0;y<z;y++)
			b[y]=0;
		for(y=0;y<n;y++)
		{
			b[a[y]-min]++;
		}
		//printf("z is %lld\n",z);
		//for(y=0;y<z;y++)
		//	printf("%lld ",b[y]);
		long long int count=0;
		for(y=0;y<z;y++)
		{
			count=count+(((b[y])*(b[y]-1))/2);
		//	printf("count is %lld\n",count);
		}
		printf("%lld\n",count);
	}
	return 0;
}
