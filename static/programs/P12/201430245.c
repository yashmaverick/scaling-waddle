#include<stdio.h>
int main()
{
	while(1)
	{
		long long int t;
		scanf("%lld",&t);
		if(t!=0)
		{
			long long int a[500000];
			long long int i,j,k,l,ans=0;
			for(i=0;i<t;i++)
			{
				scanf("%lld",&a[i]);
			}
			for(i=0;i<t;i++)
			{
				for(j=i+1;j<t;j++)
				{
					if(a[j]>a[i])
					{
						ans++;
						break;
					}
				}
				k=t-1-i;
				for(j=k-1;j>=0;j--)
				{
					if(a[j]>a[k])
					{
						ans++;
						break;
					}
				}
				for(j=i+1;j<t;j++)
				{
					if(a[j]==a[i])
					{
						ans++;
					}
					if(a[j]>a[i])
					{
						break;
					}
				}
			}
			l=(t*(t-1))/2-ans;
			printf("%lld\n",l);
		}
		else
		{
			break;
		}
	}
	return 0;
}
