#include<stdio.h>
long long int fun(long long int a[] , long long int max , long long int temp )
{
	long long int i,j,temp1=0,max1,min1;
	if( temp==0 )
	{
		if( max>=0 )
			printf("%lld\n",max);
		else
			printf("0\n");
		return 0;
	}
	min1=a[0];
	for( i=0 ; i<temp ; i++ )
	{
		if( min1>a[i] )
		{
			min1 = a[i];
			temp1=i;
		}
	}
	max1=min1;
	for( i=temp1+1 ; i<temp ; i++ )
	{
	       if( max1<a[i] )
		    max1=a[i];
	}
	max1=max1-min1;
	if( max1>max )
		max=max1;
//	printf("%lld\n",max1);

	fun(a,max,temp1);
}
int main()
{
	long long int min,max,a[100000],temp,T,t,i,j,k,n;
	scanf("%lld",&T);
	for( t=0 ; t<T ; t++ )
	{
		scanf("%lld%lld",&n,&a[0]);
		min=a[0];
		temp=0;
		max=0;
		for( i=1 ; i<n ; i++ )
		{
			scanf("%lld",&a[i]);
			if( min>a[i] )
			{
				min=a[i];
				temp=i;
			}
		}
		max=min;
		for( i=temp+1 ; i<n ; i++ )
		{
			if( max<a[i] )
				max=a[i];
		}
		max=max-min;
//		printf("%lld%lld\n",min,max);
		fun(a,max,temp);
	}
	return 0;
}	
