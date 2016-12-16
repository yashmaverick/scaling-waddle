#include<stdio.h>
long long int b[1000000],a[1000000];
int main()
{
	long long int t,i,n,j,l;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		long long int min=10000001,max=-10000001;
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			if(min>a[j])
				min=a[j];
		}
		long long int s=0;
		for(l=0;l<1000000;l++)
			b[l]=0;
		for(l=0;l<n;l++)
			b[a[l]-min]++;
		for(l=0;l<1000000;l++)
			s=s+((b[l])*(b[l]-1))/2;
		printf("%lld\n",s);
	}
	return 0;
}

