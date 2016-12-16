#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int a[n],i,p=0,state,count=0,max,max1;
		long long int s[n][2];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			s[i][1]=0;
			s[i][0]=0;
		}
		max=a[0];
		max1=a[n-1];
		for(i=1;i<n;i++)
		{
			if(a[i]>=max)
				max=a[i];
			else
				count++;
			if(a[n-1-i]>=max1)
				max1=a[n-1-i];
			else
				count++;
		}
		s[0][0]=a[0];
		s[0][1]=1;
		p=1;
		for(i=1;i<n;i++)
		{
			if(a[i]<s[p-1][0])
			{
				s[p][0]=a[i];
				s[p][1]=1;
				p++;
			}
			else if(a[i]==s[p-1][0])
			{
				count+=s[p-1][1];
				s[p-1][1]++;
			}
			else
			{
				while(a[i]>s[p-1][0])
				{
					p--;
					if(p==0)
					{
						s[0][0]=a[i];
						s[0][1]=1;
						p++;
						break;
					}
					else if(a[i]<s[p-1][0])
					{
						s[p][0]=a[i];
						s[p][1]=1;
						p++;
						break;
					}
					else if(a[i]==s[p-1][0])
					{
						count+=s[p-1][1];
						s[p-1][1]++;
						break;
					}
				}
			}
		}
		long long int ans=n*(n-1)/2-count;
		printf("%lld\n",ans);
		scanf("%lld",&n);
	}
	return 0;
}
