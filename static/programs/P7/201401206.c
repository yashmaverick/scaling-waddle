#include<stdio.h>


int main()
{

	int t;
	scanf("%d",&t);

	while(t--)
	{
		long long int n,i;
		scanf("%lld",&n);
		long long int a[n],min,max;
		scanf("%lld",&a[0]);
		min=a[0];
		max=a[0];

		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		long long int b[1000010]={0};
		long long int count=0;


		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;
			b[a[i]]++;
		//	printf("##%lld %lld##\n",a[i],b[a[i]]);
		}
		int j=0;
		for(i=min,j=0;i<=max;i++,j++)
		{
			if(b[j]>1)
			{
				count=count+(((b[j])*(b[j]-1))/2);
			//		printf("***%lld***\n",count);
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}





