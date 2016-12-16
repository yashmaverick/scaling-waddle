#include<stdio.h>
#include<math.h>
int lower_bound(long long int z[],int low, int high, long long int e)
{
	if ( low < 0) return 0;
	if (low>=high )
	{
		if ( e <= z[low] ) return low;
		return low+1;
	}
	int mid=(low+high)/2;
	if ( e> z[mid])
		return lower_bound(z,mid+1,high,e);
	return lower_bound(z,low,mid,e);

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int p,q,r,i;
		scanf("%lld",&p);
		long long int a[p],count=0;
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		long long int b[q];
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		long long int c[r];
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		long long int bs[q],as[r];
		long long int s=fmin(q,r);
		long long int d=fmin(p,q);
		bs[0]=lower_bound(c,0,r,b[0]);
		//printf("%lld\n",bs[0]);
		for(i=1;i<s;i++)
			bs[i] =lower_bound(c,i,r,b[i]);
/*		for(i=0;i<s;i++)printf("%lld ",bs[i]);
		printf("\n");
		*/
		for(i=0;i<s;i++)
			bs[i]=r-bs[i];
		for(i=s-2;i>=0;i--)
			bs[i] = bs[i] + bs[i+1];
		/*		for(i=0;i<s;i++)printf("%lld ",bs[i]);
				printf("\n");
				*/
		for(i=0;i<d;i++)
		{
			if(lower_bound(b,i,s, a[i])<s)
				count+=bs[lower_bound(b,i,s, a[i])];
		}
		printf("%lld\n",count);
	}
	return 0;
}
