#include<stdio.h>
typedef long long int ll;
void sort(ll a[],ll l,ll r)
{
	ll mid=l+(r-l)/2;
	if(r-l==1)
		return ;
	sort(a,l,mid);
	sort(a,mid,r);
	ll b[1000],i,j=0,k;
	for(i=l;i<mid;i++)
		b[j++]=a[i];
	i=0;j=mid;k=l;
	while(i<(mid-l) && j<r)
		a[k++]=(b[i]>a[j])?a[j++]:b[i++];
	while(i<(mid-l))
		a[k++]=b[i++];
}
int main()
{
	ll test,n,k;
	scanf("%lld",&test);
	ll i,j;
	for(i=0;i<test;i++)
	{
		scanf("%lld %lld",&n,&k);
		char c;
		ll a[n];
		ll v=0;

		for(j=0;j<n;j++)
		{

			while((c=getchar())!=' ');
			scanf("%lld",&a[j]);

		}
		sort(a,0,n);
	/*	for(j=0;j<n;j++)
		{
			printf("%lld",a[j]);
		}*/
		for(j=0;j<n-2;j++)
		{
			ll f=j+1;
			ll l=n-1;
			v=0;
			while(f<l)
			{
				ll sum=(a[j]+a[f]+a[l]);
				if(sum == k)
				{
					printf("YES\n");
					v=1;
					break;
				}
				else if(sum < k)
				{
					f++;
				}
				else if(sum > k)
				{
					l--;
				}
			}
			if(v==1)
			{
				break;
			}

		}
		if(v==0)
		{
			printf("NO\n");
		}
	}
	return 0;
}
