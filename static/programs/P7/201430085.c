#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void * b)
{
	return *(int*)a - *(int*)b;
}
	int main()
{
	int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		long long int n,i,temp,count=0,ans=0;
		int a[1000000];
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		qsort(a,n,4,cmpfunc);
		temp=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]==temp)
				count++;
			else
			{
				ans=ans+(count*(count+1))/2;
				temp=a[i];
				count=0;
			}
		}
	ans=ans+count*(count+1)/2;
	printf("%lld\n",ans);
	}
	return 0;
}
