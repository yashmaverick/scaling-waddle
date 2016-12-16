#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	long long int t;
		scanf("%lld",&t);
	while(t--)
	{
		long long int i,j,k,l,mi=0,n;
		long long int left,right;
		long long int a[100001];
		memset(a,0,100001);
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=1;i<k;i++)
		{
			if(a[i]<a[mi])
				mi=i;
		}
		if(k==n)
			{
				printf("%lld\n",a[mi]);
					continue;
			}
		printf("%lld ",a[mi]);
		right=1;left=k;
		while(left<=(n-1))
		{
			if(mi>=right&&mi<=left)
			{
				if(a[left]<a[mi])
				{
					if(left!=(n-1))
						printf("%lld ",a[left]);
					else
						printf("%lld\n",a[left]);
					mi=left;
				}
				
				else
				{
					if(left!=(n-1))
					printf("%lld ",a[mi]);
					else
					printf("%lld\n",a[mi]);
				}
			}
			else
			{
				mi=right;

				for(i=right+1;i<=left;i++)
					if(a[i]<a[mi])
						mi=i;
				if(left!=(n-1))
					printf("%lld ",a[mi]);
				else
					printf("%lld\n",a[mi]);
			}
			left++;right++;
		}		
	}
	return 0;
}