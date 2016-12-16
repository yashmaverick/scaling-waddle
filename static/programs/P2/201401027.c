#include<stdio.h>
long long int a[100010],b[100010],c[100010],p1[100010],p2[100010];
long long int search(long long int Array[],long long int val, long long int i, long long int j,long long int t)
{
	long long int mid,ind=0;
	if(i<=j)
	{
		while(i<=j)
		{
			mid=(i+j)/2;
			if(Array[mid]<val)
				i=mid+1;
			else if(Array[mid]>val)
				j=mid-1;
			else
			{
				j=mid-1;
				ind=mid;
			}
		}
		if(ind!=0)
			return ind;
		else if(Array[mid]>=val)
			return mid;
		else if(mid+1<t && Array[mid+1]>=val)
			return mid+1;
		else
			return t;
	}
	return t;
}
int main()
{
	long long int min,tc,k,p,q,r,i,j,ans=0;
	scanf("%lld",&tc);
	for(k=0;k<tc;k++)
	{
		ans=0;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		for(i=0;i<q;i++)
		{
			min=search(c,b[i],i,r-1,r);
			//printf("%lld\n",min);
			p1[i]=r-min;
		}
		p2[q-1]=p1[q-1];
		for(i=q-2;i>=0;i--)
			p2[i]=p2[i+1]+p1[i];
		min=(p<q)?p:q;
		for(i=0;i<min;i++)
		{
			j=search(b,a[i],i,q-1,q);
			if(j<q)
				ans+=p2[j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
