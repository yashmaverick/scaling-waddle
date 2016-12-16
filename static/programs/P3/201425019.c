#include<stdio.h>
int main()
{
	long long int a[100000],min,prof;
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);

		for(i=0; i<n; i++)
		scanf("%lld",&a[i]);
		
		min=a[0];
		prof=a[1]-a[0];
		for(i=0; i<n; i++)
		{
			if(a[i]-min>prof)
			prof=a[i]-min;
			if(a[i]<min)
			min=a[i];
		}
		/*if(a[max]>a[min] && min<max)
		prof=a[max]-a[min];
		else
		prof=0;*/

		printf("%lld\n",prof);
	}
	return 0;
}
