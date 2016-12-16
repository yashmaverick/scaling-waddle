#include<stdio.h>
int main()
{
	int test;
	long int minimum,ans;
	scanf("%d",&test);
	while(test>0)
	{
		long int i,nu;
		scanf("%ld",&nu);
		long int b[1000001]={0};
		long int a[nu];
		ans=0;
		scanf("%ld",&a[0]);
		minimum=a[0];
		for(i=1;i<nu;i++)
		{
			scanf("%ld",&a[i]);
			if(a[i]<minimum)
				minimum=a[i];
		}
		for(i=0;i<nu;i++)
		{
			b[a[i]-minimum]++;
		}
		for(i=0;i<1000001;i++)
		{
			if(b[i]>1)
				//	{printf("%ld   ",ans);
				ans=ans+(b[i]*(b[i]-1))/2;
		}
		printf("%ld\n",ans);
		test--;
		}
		return 0;
	}
