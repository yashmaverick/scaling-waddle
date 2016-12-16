#include<stdio.h>
typedef long long int ll;
int main()
{
	ll test;
	ll i;
	scanf("%lld",&test);
	for(i=0;i<test;i++)
	{
		ll n;
//		ll k;
		ll j;
		scanf("%Ld",&n);
		ll a[n];
		ll min;
		ll max;
		scanf("%Ld",&a[0]);
		min=max=a[0];
		for(j=1;j<n;j++){
			scanf("%lld",&a[j]);
			if(min > a[j])
				min=a[j];
			if(max < a[j])
				max=a[j];
		}
		

		ll b[max-min+1];
			ll t;
			ll r=max-min+1;
			//		count=1
			for(t=0;t<r;t++)
			{
				b[t]=0;
			}

			for(j=0;j<n;j++)
			{
				b[a[j]-min]=b[a[j]-min]+1;	
			}
			ll m=0;
			ll l=0;
			for(j=0;j<r;j++)
			{
				
				l=b[j];
				m=m+((l*(l-1))/2);
			}
		
			
			printf("%Ld\n",m);
			//		return 0;
		}

		return 0;


	}


