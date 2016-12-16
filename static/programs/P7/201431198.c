#include<stdio.h>
int main()
{
		int t;
		scanf("%d", &t);
		while(t--)	
		{
			long long int a[1000001],b[1000001],i,count=0,n,min;
			scanf("%lld",&n);
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			min=a[0];
			for(i=0;i<n;i++)
			{
				if(a[i]<=min)
					min=a[i];
			}
			for(i=0;i<n;i++)
				a[i]=a[i]-min;
			for(i=0;i<1000001;i++)
				b[i]=0;
			for(i=0;i<n;i++)
				b[a[i]]++;
			for(i=0;i<1000001;i++)
				count=count+(b[i]*(b[i]-1))/2;
			printf("%lld\n",count);
		}
		return 0;
}