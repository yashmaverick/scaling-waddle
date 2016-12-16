#include<stdio.h>
#include<stdlib.h>
int main()
{
	 long long int *b;
	 b=(long long int *)malloc(sizeof(long long int)*1000000);
		long long int i,j,k,l,n,m,r,min,l1,l2;
	long long int ans=0;
	scanf("%lld",&m);
	for(r=0;r<m;r++)
	{
		ans=0;
		scanf("%lld",&n);
	long long int *a;
	 a=(long long int *)malloc(sizeof(long long int)*1000000);
		//min=10000000;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		
		}
		min=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]<=min)
				min=a[i];
		}
		for(k=0;k<n;k++)
		{
			a[k] =(a[k] - min);
		}
		for(l=0;l<1000000;l++)
		{
			b[l]=0;
		}
		for(l1=0;l1<n;l1++)
		{
			(b[a[l1]])++;
		}
		for(l2=0;l2<1000000;l2++)
		{
			ans = ans+(((b[l2])*(b[l2]-1))/2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
