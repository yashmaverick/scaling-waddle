#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(;n>0;n--)
	{
		long long int s,i;
		scanf("%lld",&s);
		long long int a[s];
		for(i=0;i<s;i++)
			scanf("%lld",&a[i]);
		long long int max=0,min=a[0];	
		for(i=0;i<s;i++)
		{
			if(a[i]-min>max)
				max=a[i]-min;
			if(a[i]<min)
				min=a[i];
		}
		printf("%lld\n",max);
	}
	return 0;
}
