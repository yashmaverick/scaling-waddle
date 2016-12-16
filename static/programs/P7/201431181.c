#include<stdio.h>
long long int a[1000005],b[1000005],k;
int main()
{
	int T;
	scanf("%d",&T);
	long int i,min,t,n;
	for( t=0 ; t<T ; t++ )
	{
		scanf("%ld%lld",&n,&a[0]);
		min=a[0];
		for( i=1 ; i<n ; i++ )
		{
			scanf("%lld",&a[i]);
			if( min>a[i] )
				min=a[i];
		}
		for( i=0 ; i<n ; i++ )
			a[i]=a[i]-min;		for(i=0;i<1000005;i++)
				b[i]=0;
		for(i=0;i<n;i++)
		{
			b[a[i]]++;
		}
		k=0;
		for(i=0;i<1000005;i++)
		{
			k=k+(b[i]*(b[i]-1))/2;
		}
		printf("%lld\n",k);}
	return 0;
}
