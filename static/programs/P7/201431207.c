#include<stdio.h>
int main()
{
	int test,h;
	scanf("%d",&test);
	for(h=0;h<test;h++)
	{
		long int i,k,b[1000001]={0},min,max,ans=0,temp;
		scanf("%ld",&k);
		long int a[k];
		for(i=0;i<k;i++)
			scanf("%ld",&a[i]);
		min=max=a[0];
		for(i=0;i<k;i++)
		{
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		max=max-min;
		for(i=0;i<k;i++){
			long int j=a[i]-min;
			b[j]++;
		}

		for(i=0;i<=1000000;i++)
		{
		
					temp=(b[i]*(b[i]-1))/2;
					ans=ans+temp;
		}	
		printf("%ld\n",ans);
	}
	return 0;
}
