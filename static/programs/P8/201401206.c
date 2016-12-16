#include<stdio.h>

long long int power(long long int d,long long int x,long long int n)
{
	long long int val;
	if(d==0)
		return 1;
	val=(power(d/2,x,n))%n;
	if(d%2==0)
		return (val*val)%n;
	else
		return (val*val*x)%n;

}       

long long int powe(int x)
{
	int i=0,val=1;
	if(x==0)
		return 1;
	for(i=0;i<x;i++)
	{
		val=(val*26)%100007;
	}
	return val;
}       

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		long long int mxv,d,a[40];
		int i,j,k,m,n;
		scanf("%lld %lld %d %d",&mxv,&d,&m,&n);
		for(i=0;i<n;i++)
		{
			a[i]=power(d,i,n);
		//	printf("%lld\n",a[i]);
		}
		long long int r,w,e,ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(((a[i]+a[j]+a[k])%n==m) && (i<=mxv) && (j<=mxv) && (k<=mxv))
					{
						//	if(a[i]<=(mxv%n))
						r=(((mxv-i)/n)+1)%1000000007;
						//	else
						//		r=(mxv/n)%1000000007;
						//	if(a[j]<=(mxv%n))
						w=(((mxv-j)/n)+1)%1000000007;
						//	else
						//		w=(mxv/n)%1000000007;
						//	if(a[k]<=(mxv%n))
						e=(((mxv-k)/n)+1)%1000000007;
						//	else
						//		e=(mxv/n)%1000000007;	
						ans+=((r*w)%1000000007*e)%1000000007;
					}
				}
			}
		}
		ans=ans%1000000007;
		printf("%lld\n",ans);
	}
	return 0;
}

