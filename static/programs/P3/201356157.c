#include <stdio.h>
#include <stdlib.h>
long long int max (long long int array[100000],long long int a,long long int n)
{
	long long int k,x;
	k = array[a];
	for(x=a+1;x<n;x++)
	{
		if(array[x]>k)
			k = array[x];
	}
	return k;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		long long int n,i,diff=0,min,q;
		scanf("%lld",&n);
		long long int array[n]; 
		scanf("%lld",&array[0]);
		min =array[0];
		for(i=1;i<n;i++)
		{
			scanf("%lld",&array[i]);
			if(array[i-1]<=min)
				min = array[i-1];
			if(diff<(array[i]-min))
				diff = array[i]-min;
		}
		i=0;
		
		printf("%lld\n",diff);
	}
	return 0;
}