#include<stdio.h>
#include<string.h>
typedef long long int ll;
/*ll partition(ll a[],ll s,ll e)
  {
  ll pind=s;
  ll piv=a[e];
  ll i,j,k;
  ll temp;
  for(i=s;i<e;i++)
  {
  if(a[i] <= piv)
  {
  temp=a[i];
  a[i]=a[pind];
  a[pind]=temp;
  pind=pind+1;
  }
  }
  temp=a[pind];
  a[pind]=a[e];
  a[e]=temp;
  return pind;
  }

  void quicksort(ll a[],ll s,ll e)
  {
  ll r;
  if(s >= e)
  return;
  else
  {
  (r=partition(a,s,e);
  quicksort(a,s,r-1);
  quicksort(a,r+1,e);
  }
  }*/

void msort(ll a[],ll l,ll r)
{
	ll mid=l+(r-l)/2;
	if(r-l==1)
		return ;
	msort(a,l,mid);
	msort(a,mid,r);
	ll b[100000],i,j=0,k;
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
	ll c,b;
	scanf("%lld",&b);
	for(c=0;c<b;c++)
	{ll n;
		ll i,e;
		scanf("%lld %lld",&n,&e);
		ll a[n];
		char s[n];
		for(i=0;i<n;i++)
		{scanf("%s",s);
			scanf("%lld",&a[i]);
		}
		msort(a,0,n);
			//	for(i=0;i<n;i++)
			//		printf("%lld",a[i]);

		ll d2,d3,x,y=1;
		for(x=0;x<n-2;x++)
		{
			d2=x+1;d3=n-1;
			while((d2<d3) && (d2!=d3))
			{
				if(a[x]+a[d2]+a[d3]>e)
					d3--;
				else if(a[x]+a[d2]+a[d3]<e)
					d2++;
				else if(a[x]+a[d2]+a[d3]==e)
				{
					y=2;
					break;
				}
			}
			if(y==2)
			{		
				break;
			}
		}
		if(y==2)

				printf("YES\n");

		else if(y==1)
			printf("NO\n");



	}
	return 0;
}

