#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int ans,max,min,i,n;			
		scanf("%lld",&n);
		long long int a[n];
		ans=0;
		//scanf("%lld",&a[0]);
		max=min=0;
		//b[0]=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
			else if(a[i]>max)
				max=a[i];
		}
		long long int b[max-min+1];
		for(i=0;i<max-min+1;i++)
			b[i]=0;
		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;
			b[a[i]]++;
		}
		//printf("%lld\n",max);
		//printf("%lld\n",min);
		for(i=0;i<max-min+1;i++)
		{
			//	printf("%lld ",b[i]);
			ans=ans+((b[i]*(b[i]-1))/2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
