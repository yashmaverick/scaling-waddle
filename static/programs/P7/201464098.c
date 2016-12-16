#include<stdio.h>
#include<stdlib.h>
int luck(const void *a,const void *b)
{
	return (*(long long int*)a-*(long long int*)b);
}
int main()
{
	long long int t,g;
	scanf("%lld",&t);
	for(g=0;g<t;g++)
	{
		long long int i,n,count=0;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		qsort(a,n,sizeof(long long int),luck);
		long long int k=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				k++;
			else
			{
				count=count+(k*(k-1))/2;
				k=1;
			}
		}
		count=count+(k*(k-1))/2;
		printf("%lld\n",count);
	}
	return 0;
}