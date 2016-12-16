#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int i;
		int b[1000001];
		int a[1000001];
		for(i=0;i<1000001;i++)
			b[i]=0;
		scanf("%d",&n);
		scanf("%d",&a[0]);
		long long int min=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
				min=a[i];
		}
		for(i=0;i<n;i++)
		{
			    b[a[i]-min]++;                                     
		}
		long long int sum=0;
		for(i=0;i<1000001;i++)
		{
			sum=sum+((long long int)b[i]*(long long int)(b[i]-1))/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
