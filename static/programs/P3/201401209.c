#include<stdio.h>
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n,i;
		scanf("%d",&n);
		long long int a[n];
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		long long int max=0,min=0,ans=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>=a[max]) max=i;
			if(a[i]<a[min]) min=i;
//			printf("%lld %lld \n",max,min);
			if(max>=min && a[max]-a[min]>ans) ans=a[max]-a[min];
			else if(min>max) max=min;
		}
			if(max>=min && a[max]-a[min]>ans) ans=a[max]-a[min];
		
		printf("%lld\n",ans);
	}
	return 0;
}
