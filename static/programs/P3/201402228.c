#include<stdio.h>
int main()
{
	int t,i;
	long long int a[100000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int n,j,max,k,pro=0,l;
		scanf("%lld",&n);
		for(l=0;l<n;l++)
		{
			scanf("%lld",&a[l]);
		}
		max=a[n-1];
		for(j=n-2;j>=0;j--)
		{
			if(a[j]>max)
				max=a[j];
			if(max-a[j]>pro)
				pro=max-a[j];
		}

		printf("%lld\n",pro);
	}
	return 0;
}





