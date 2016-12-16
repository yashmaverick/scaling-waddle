#include<stdio.h>
#include<math.h>
long long int a[100001],b[100001],c[100001],d[100001];
long long int bins(long long int a[],long long int m,long long int low,long long int high)
{
	if(a[low]==a[high])
		return low;
	while(low<=high)
	{
		long long int mid=(low+high)/2;
		if(a[mid]==m)
			return (mid);
		else if(a[mid]>m)
			high=mid;
		else if(a[mid]<m)
			low=mid+1;
		if(low>high)
			return ;  
		if(low==high)
			return high;
	}
}
int main()
{
	long long int t;	
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		long long int x,y,z,i,q,sum;
		scanf("%lld",&x);
		for(i=0;i<x;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&y);
		for(i=0;i<y;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&z);
		for(i=0;i<z;i++)
			scanf("%lld",&c[i]);
		for(i=0;i<y;i++)
			d[i]=0;
		for(i=0;i<z;i++)
		{
			if(c[z-1]>=b[i])
			{
				q=bins(c,b[i],0,z-1);
				if(q==z)
					q=z-1;
				if(q<i)
					q=i;
				d[i]=z-q;
			}
			else
				d[i]=0;

		}
		/*for(i=0;i<y;i++)
			printf("%lld ",d[i]);
		printf("\n");
		*/
		for(i=y-2;i>=0;i--)
			d[i]=d[i]+d[i+1];
	/*	for(i=0;i<y;i++)
			printf("%lld ",d[i]);
		printf("\n");
		*/
		sum=0;
		long long int s=fmin(x,y);
		for(i=0;i<s;i++)
		{
			if(b[y-1]>=a[i])
			{
				q=bins(b,a[i],0,y-1);
				if(q==y)
					q=y-1;
				if(q<i)
					q=i;
				sum=sum+d[q];
			}
			else
				break;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
