#include<stdio.h>
int main()
{
	while(1)
	{
	long long int a[500000],n,i,j;
	scanf("%lld",&n);
	if(n==0)
		return 0;

	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long int count=0;
/*	int m1=a[0];
	for(i=0;i<n;i++)
	{
		if(m1<a[i])
			m1=a[i];
	}
*/
	for(i=0;i<n-2;i++)
	{
		long long int max=a[i+1];
		for(j=i+2;j<n;j++)
		{
		if(max>a[i] || max>a[j])
			{
				count++;
			}

			if(max<a[j])
				max=a[j];
		}
	}
	printf("%lld\n",count);
	}
	return 0;
}
