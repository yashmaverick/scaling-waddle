#include<stdio.h>
long long int ans,u;
long long int binary_search(long long int a[],long long int low,long long int high,long long int k,long long int n,long long int i)
{
	if(k>=a[i] && a[n-1]>=k)
	{
		if(low==high)
		{
			ans=low;
			//		return low;
		}
		else
		{
			int mid;
			mid=(low+high)/2;
			if(k<=a[mid])
				binary_search(a,low,mid,k,n,i);
			if(k>a[mid])
				binary_search(a,mid+1,high,k,n,i);
		}
	}
	else
	{
		//		printf("$$\n");
		if(k<a[i])
			ans=i;
		if(k>a[n-1])
			ans=n;
		return;
	}

}

int geo(long long int a[],long long int low,long long int high,long long int k,long long int n,long long int i)
{
	if((high-low)>82)
	{
		long long int z=0,u;
		while(1)
		{
			if(a[z]>k)
			{
				z=z*3;
				u=z;
			}
			else
			{
				geo(a,u,z,k,n,i);
			}


		}
	}
	else
		binary_search(a,low,high,k,n,i);
}



int main()
{
	int v,h;
	scanf("%d",&v);
	for(h=0;h<v;h++)
	{
		long long int n,i,index,k,n1,n2,result=0;
		scanf("%lld",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&n1);
		long long int b[n1],t[n1];
		for(i=0;i<n1;i++)
		{
			scanf("%lld",&b[i]);
		}
		scanf("%lld",&n2);
		long long int c[n2];
		for(i=0;i<n2;i++)
		{
			scanf("%lld",&c[i]);
		}
		for(i=(n1-1);i>=0;i--)
		{
			binary_search(c,i,n2-1,b[i],n2,i);
			//		printf("%d",ans);
			//		if(ans>=i)
			//		{
			if(i==n1-1)
				t[i]=n2-ans;
			else
				t[i]=(n2-ans)+t[i+1];
			//		}
		}
		//	for(i=0;i<n1;i++)
		//		printf("%d ",t[i]);
		//		printf("\n");
		for(i=0;i<n;i++)
		{
			binary_search(b,i,n1-1,a[i],n1,i);
			//		printf("%d\n",ans);
			if(ans<n)
				result+=t[ans];
		}
		printf("%lld\n",result);
	}
	return 0;
}

