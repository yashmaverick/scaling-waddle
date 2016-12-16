#include<stdio.h>
long long int permut(long long int a)
{

	long long int r;
	r=a*(a-1)/2;
	return r;
}
long long int comb(long long int hash[],long long int diff)
{
	long long int r,i=0;
	for(r=0;r<diff;r++)
		i=permut(hash[r])+i;
	return i;
}

int main()
{
	long long int t,d;
	scanf("%lld",&d);
	for(t=0;t<d;t++)
	{
		long long int n;
		scanf("%lld",&n);
		long long int a[n],i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int j=0,max=-10000000,ans=0;
		for(j=0;j<n;j++)
		{
			if(abs(a[j])>max)
				max=abs(a[j]);
		}
/*		long long int h,min=10000000;
		for(h=0;h<n;h++)
		{
			if(a[h]<min)
				min=a[h];
		}
		long long int ans=0,diff=max-min;*/
//printf("%lld",max);		
if(max==0)
ans=permut(n);
else
{
long long int hash[3*max];
		for(i=0;i<3*max;i++)
			hash[i]=0;
		for(i=0;i<n;i++)
		{
			hash[max+a[i]]++;
		}
		//printf("%d\n",hash[);		
		
		ans=comb(hash,3*max);
}
		printf("%lld\n",ans);

	}
	return 0;
}

