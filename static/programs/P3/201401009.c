#include<stdio.h>
//#include "StdAfx.h"
long long int min=100000000000;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long int min=100000000;
		long long int m,max,maxdiff;
		long long int a[100000],i;
		scanf("%lld",&m);
		max=0,maxdiff=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&a[i]);
			if(min>a[i])
			{
					min=a[i];
			}
			/*if(max<a[i])
			{
				max=a[i];
				k=i;
			}*/
			if(maxdiff<(a[i]-min))
				maxdiff=a[i]-min;
		}
		printf("%lld\n",maxdiff);
	}
return 0;
}