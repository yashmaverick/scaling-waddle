#include<stdio.h>
long long int func(long long int a[],long long int f,long long int l)
{
	if(f<l)
	{
		long long int m,flag=0;
		m=(f+l)/2;
		long long int j=m-1,k=m+1,c=a[m],area=0;
		long long int max_area;
		if(f==l-1)
		{
			long long int max,min,ans;
			if(a[0]<=a[1])
				max=a[1];
			if(a[0]>=a[1])
				max=a[0];
			if(max>=2*min)
				ans=max;
			if(max<=2*min)
				ans=min;	
			return ans;
		}
		if(func(a,f,m-1)>=func(a,m+1,l))
			max_area=func(a,f,m-1);
		else
			max_area=func(a,m+1,l);
		while(flag==0)
		{
			while(j>=f && a[j]>=c)
				j--;
			while(k<=l && a[k]>=c)
				k++;
			area=(k-j-1)*c;
			if(j>=f && k<=l)
			{
				if(a[j]>=a[k])
					c=a[j];
				else
					c=a[k];
			}
			else
			{
				if(j<f)
					c=a[k];
				if(k>l)
					c=a[j];
				if(j<f && k>l)
					flag=1;
			}
			if(area>=max_area)
				max_area=area;
		}
		return max_area;
	}
}
int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int i,a[100000],min=1000000;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
		}
		long long int ans;
		if(n==1)
			ans=a[0];
		//else
		//ans=func(a,0,n-1);
		else if(n==2)
		{
			long long int max;
			if(a[0]<=a[1])
				max=a[1];
			if(a[0]>=a[1])
				max=a[0];
			if(max>=2*min)
				ans=max;
			if(max<=2*min)
				ans=min;
		}
		else
			ans=func(a,0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
