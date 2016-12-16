#include<stdio.h>
int main()
{
	int a[1000000],i,j,n,test,min,count[1000000],max;
	long long int res;
	scanf("%d",&test);
	for(j=0;j<test;j++)
	{
		res=0;
		for(i=0;i<1000001;i++)
			count[i]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i==0)
			{
				min=a[i];
				max=a[i];
			}
			else if(a[i]<min)
				min=a[i];
			else if(a[i]>max)
				max=a[i];
		}
		for(i=0;i<n;i++)
		{
			count[a[i]-min]++;
		}
	//	for(i=0;i<=(max-min);i++)
	//		printf("%d ",count[i]);
		for(i=0;i<=(max-min);i++)
		{
			if(count[i]>1)
			{
				res+=((long long)(count[i])*(long long)(count[i]-1))/2;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
