#include<stdio.h>
#include<math.h>
long long int a[100001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,i;
		scanf("%lld",&n);
		long long int max;
		long long int count=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		max=a[n-1];
		for(i=n-2;i>=0;i--)
		{
			max=fmax(max,a[i]);
			count=fmax(count,max-a[i]);
		}
		printf("%lld\n",count);
	}
	return 0;
}
