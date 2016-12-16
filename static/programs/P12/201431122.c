

#include<stdio.h>
long long int s[500005];
long long int tp=0;
int main()
{
	long long int n,i,j,a[500005];
	long long int ans,nc;
	while(1)
	{
		scanf("%lld",&n);
		nc=0;
		tp=0;
		if(n==0)
			break;
		else{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			i=0;
			while(i<n)
			{
				if(tp==0)
					s[++tp]=a[i++];
				else if(s[tp]==a[i])
				{
					int temp =tp;
					while(temp>0)
					{
						if(s[temp]>a[i])
						{
							nc++;
							break;
						}
						else
						{
							nc++;
							temp--;
						}
					}
					s[++tp]=a[i++];
				}
				else if(s[tp]>a[i])
				{
					s[++tp]=a[i++];
					nc++;
				}
				else
				{
					tp--;
					nc++;
				}
			}
			ans = (n*(n-1)/2)-nc;
			printf("%lld\n",ans);
		}
	}

return 0;
}
