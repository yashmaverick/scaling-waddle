#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		long long int c=1,count=0;
		scanf("%d",&n);
		int a[n],b[1000001]={0},min;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i==0)
				min=a[i];
			if(a[i]<min)
				min=a[i];

		}
		//printf("%d\n",min);
		for(i=0;i<n;i++)
		{
			b[a[i]-min]++;
			//printf("Increased for %d\n",a[i]-min);
		}
		for(i=0;i<1000001;i++)
		{
			c=b[i];
			count=count+(c*(c-1))/2;
		}
		printf("%lld\n",count);
	}
	return 0;
}


