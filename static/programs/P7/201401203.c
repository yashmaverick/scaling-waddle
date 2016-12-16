#include<stdio.h>

int a[1000001];
unsigned long long int b[1000001];
int main()
{
	int i,j,t,n,min,max;
	unsigned long long int sum=0;
	scanf("%d",&t);
	while(t--)
	{
		 min=10000000,max=-10000000;
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		for(i=0;i<n;i++)
			b[a[i]-min]++;
		for(i=0;i<=max-min;i++)
		{
			if(b[i]>1)
				sum+=(b[i]*(b[i]-1))/2;
		}
		printf("%llu\n",sum);
		for(i=0;i<=max-min;i++)
			b[i]=0;
	}
	return 0;
}
