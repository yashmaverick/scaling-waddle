#include<stdio.h>
typedef long long int ll;
ll cmpfunc (const void * a, const void * b)
{
	   return ( *(ll*)a - *(ll*)b );
}
ll bsrc(ll *a,ll m,ll size,ll init)
{
	ll i,c=0,l,u,mid;
	l=init,u=size-1;
	while(l<=u){
		mid=(l+u)/2;
		if(m==a[mid]){
			c=1;
			break;
		}
		else if(m<a[mid]){
			u=mid-1;
		}
		else
			l=mid+1;
	}
	if(c==0)
		return 0;
	else
		return 1;
}
ll main()
{
	ll test,j,i,n,k,l;
	scanf("%lld",&test);
	while(test--)
	{
		ll flag=0;
		char c[10000];
		ll sum=0;
		scanf("%lld %lld",&n,&k);
		//int*a=(int*)malloc(sizeof(int)*n);
		//int*arr=(int*)malloc(sizeof(int)*n);
		ll arr[1001];
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%lld",&arr[i]);
		}
		qsort(arr,n, sizeof(ll), cmpfunc);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				sum=k-arr[i]-arr[j];
				ll e=bsrc(arr,sum,n,j+1);
				if(e==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
