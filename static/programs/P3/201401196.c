#include <stdio.h>
int main()
{
	int t,i,j,k;
	long int n;
	long long int a[100000],min,max,profit;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		min=a[0];max=0;
		long long  int ans=0;
		for(j=1;j<n;j++)
		{
			if(a[j]-min>ans){
				ans=a[j]-min;
			}
			else{
				if(a[j]<min){
					min=a[j];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
