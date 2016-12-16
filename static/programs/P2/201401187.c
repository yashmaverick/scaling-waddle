#include<stdio.h>
#include<math.h>
long long int a[100000],b[100000],c[100000];
long long int binaryl(long long int a[],long long int l,long long int h,long long int x,long long int n)
{
	if(l>h)
		return 0;
	long long int m=(l+h)/2;
	if(a[m]<=x&&a[m+1]>x)
		return m+1;
	else if(a[m]>x)
		return binaryl(a,l,m-1,x,n);
	else
		return binaryl(a,m+1,h,x,n);
}
long long int binaryr(long long int c[],long long int l,long long int h,long long int x,long long int n)
{
	if(l>h)
		return 0;
	long long int  m=(l+h)/2;
	if(c[m]<x&&c[m+1]>=x)
		return n-m-1;
	else if(c[m]>=x)
		return binaryr(c,l,m-1,x,n);
	else
		return binaryr(c,m+1,h,x,n);

}
int main()
{
	long long int x,y,z,t,cnt,p,q,r,i;
	scanf("%lld",&t);
	while(t--)
	{
		cnt=0;//assigning count=0
		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		z=fmin(q,r);
		for(i=0;i<z;i++)//loop goes upto the min of q and r as j<=k
		{
			if(b[i]<a[0])
				x=0;
			else if(b[i]>=a[p-1])
				x=p;
			else
				x=binaryl(a,0,p-1,b[i],p);//returns index where a[index]>b[i]
			if(b[i]<=c[0])
				y=r;
			else if(b[i]>c[r-1])
				y=0;
			else
				y=binaryr(c,0,r-1,b[i],r);//returns index where c[index]<b[i]
			cnt+=fmin(x,i+1)*fmin(y,r-i);
		}
		printf("%lld\n",cnt);
	}
	return 0;
}



