#include<stdio.h>
long long int n;
long long int func1(long long int b,long long int e)
{
	long long int ans=1;
	while(e>0)
	{
		if(e%2==0)
			b=b%n;
		else
			ans=((ans%n)*(b%n))%n;
		b=((b*b))%n;
		e=e>>1;
	}
	return ans;
}
void func(long long int array[],long long int n,long long int limit,long long int e)
{
	long long int l,t;
	t=e;
	for(l=0;l<n && l<=limit;l++)
	{
		t=e;
		long long int ans=1;
		ans=func1(l,e);
		array[ans]++;
		if(limit>ans)
			array[ans]+=(limit-l)/n;
	}
	return ;
}
int main()
{
	long long int l,k;
	scanf("%lld",&k);
	while(k--)
	{
		long long int e,limit,m,i,j,ans=0;
		scanf("%lld%lld%lld%lld",&limit,&e,&m,&n);
		long long int array[43];
		for(l=0;l<n;l++)
			array[l]=0;
		m=m%n;
		func(array,n,limit,e);
		for(l=0;l<n;l++)
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)

				{
					if(((i+j+l)%n==m)&&(array[i]!=0)&&(array[l]!=0)&&(array[j])!=0)
					{
						ans=((ans%1000000007)+((((array[i]%1000000007)*(array[j]%1000000007))%1000000007)*(array[l]%1000000007))%1000000007)%1000000007;
					}
				}
			}
		printf("%lld\n",ans%1000000007);
	}
	return 0;
}


