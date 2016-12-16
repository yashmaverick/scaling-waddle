#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define min(a,b) a<b?a:b
#define ll long long int

int main()
{
	ll n,a[10010],i,k,min1[10010],min2[10010],j,t;
	scanf("%lld",&t);
	while(t--)
	{
	scanf("%lld",&n);
	scanf("%lld",&k);
	for(i=0;i<=n+2;i++)a[i]=min1[i]=min2[i]=100000000;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	
	for(i=1;i<=n;i++)
        if(i%k == 1 || k==1) 
            min1[i]=a[i];
        else
            min1[i]=min(min1[i-1], a[i]);
	
	for(i=n;i>=1;i--)
        if(i == n) 
            min2[i]=a[i]; 
        else if(i%k == 0)
            min2[i]=a[i];
        else
            min2[i]=min(min2[i+1], a[i]);
            
	//for(i=0;i<=n;i++)printf("%lld %lld %lld \n",a[i],min1[i],min2[i]);
	for(i=1;i<=n-k;i++)printf("%lld ",min(min2[i],min1[i+k-1]));

	printf("%lld\n",min(min2[n-k+1],min1[n]));
	}
	return 0;
}

