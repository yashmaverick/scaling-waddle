#include<stdio.h>
#include<string.h>
typedef long long int ll;
void sort(ll a[],ll l,ll r)
{
	ll mid=l+(r-l)/2;
	if(r-l==1)
		return ;
	sort(a,l,mid);
	sort(a,mid,r);
	ll b[100001],i,j=0,k;
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
	ll test,i,d;
	scanf("%lld",&test);
	for(i=0;i<test;i++)
	{
		char c[100001];
		scanf("%s",c);
		ll j=0;
		ll a[100001];
		ll p=20000;
		ll q=-10001;
		ll r=-9999;
		d=strlen(c);
		while(j<d)

		{
			if(c[j]=='J')
			{
				if(j==0)
					a[j]=p;
				else 
					a[j]=a[j-1]+p;
			}
			else if(c[j]=='M')
			{
				if(j==0)
					a[j]=q;
				else
					a[j]=a[j-1]+q;

			}
			else if(c[j]=='R')
			{
				if(j==0)
					a[j]=r;
				else 
					a[j]=a[j-1]+r;
			}
			j++;
		}
		sort(a,0,j);
		ll k,count1=0;
		ll count=0;
		ll s=0;
		ll sum=0;
		// for(k=0;k<j;k++)
		// printf("%lld\n",a[k]);
		a[j+1]=100000;
		ll value=a[0];
		for(k=0;k<j;k++)
		{
			if(a[k]==0)
				count1++;
				if(a[k]==value)
					count++;
				if(a[k]!=value||k==j-1)
				{	
					value=a[k];
					s=count;
					sum=sum+((s*(s-1))/2); 
					count=1;
				}

			       
		}
		sum=sum+count1;
		printf("%lld\n",sum);


	}
	return 0;
}
