#include<stdio.h>
int main()
{
	long int t;
	scanf("%ld",&t);
	while(t--)
	{
		long int n,i;
		scanf("%ld",&n);
		long int a[1000007],b[1000007],min=99999999;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			if(a[i]<min)
				min=a[i];
		}
		for(i=0;i<1000007;i++)
			b[i]=0;
		for(i=0;i<n;i++)
		{
			b[a[i]-min]++;
		}
		long int ans=0;
		for(i=0;i<1000007;i++)
		{
			b[i]=(b[i]*(b[i]-1))/2;
			ans+=b[i];
		}
		printf("%ld\n",ans);
	}
	return 0;
}
