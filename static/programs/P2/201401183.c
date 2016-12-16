#include<stdio.h>
long long int left(long long int a[], long long int st,long long int end,long long int size,long long int x)
{
	long long int m;
	if(x>=a[size-1])
		return size;
	if(x<a[0])
		return 0;
	while(st<=end)
	{   
		m=(end+st)/2;
		if(a[m]<=x&&a[m+1]>x)
			return 1+m;
		else if(x<a[m])
			return left(a,st,m-1,size,x);
		else 
			return left(a,m+1,end,size,x);
	}
}
long long int right(long long int a[],long long int st,long long int end,long long int size,long long int x) 
{
	long long int m;
	if(x<=a[0])
		return size;
	if(x>a[size-1])
		return 0;
	while(st<=end)
	{  
		 m=(end+st)/2;
		if(x>a[m]&&a[m+1]>=x)
			return size-m-1;
		else if(x<=a[m])
			return right(a,st,m-1,size,x);
		else
			return right(a,1+m,end,size,x);
	}   
}
int main()
{
	long long int t;
	long long int a[100000],b[100000],c[100000];
	long long int count,p,q,r,v,w,i;
	scanf("%lld",&t);
	while(t--)
	{
		count=0;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		for(i=0;i<(q>r?r:q);i++)
		{
			v=left(a,0,p-1,p,b[i]);
			w=right(c,0,r-1,r,b[i]);
			count+=(v<(i+1)?v:(i+1))*(w<(r-i)?w:(r-i));
		}
		printf("%lld\n",count);
	}
	return 0;
}
