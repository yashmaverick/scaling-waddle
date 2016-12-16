#include<stdio.h>
#include<stdlib.h>
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n;
		scanf("%d",&n);
		long long int a[n];
		scanf("%lld",&a[0]);
		long long int min=a[0],i,max=a[0];
		unsigned long long int ans=0;
		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min) min=a[i];
			if(a[i]>max) max=a[i];
		}
		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;
		}
//		for(i=0;i<n;i++) printf("%lld ",a[i]); printf("\n");
		max=max-min;
		unsigned long long int b[1000000]={0};
		for(i=0;i<n;i++)
		{
			b[a[i]]++;
		}
		for(i=0;i<=max;i++)
		{
			if(b[i]!=0) ans=ans+((unsigned long long int)(b[i])*(unsigned long long int)(b[i]-1))/2;
		}		
		printf("%llu\n",ans);
	}
	return 0;
}
