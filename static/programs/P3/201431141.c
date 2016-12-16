#include<stdio.h>
int main()
{
	int i,n,t,j,k,u;
	long long int A[100001],min,max,ans;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		for(k=0;k<n;k++)
			scanf("%lld",&A[k]);
		i=n-1;
		max=A[n-1];
		ans=0;
		for(j=n-2;j>=0;j--)
		{
			if(max<A[j])
				max=A[j];
			if(max-A[j]>ans)
				ans=max-A[j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
