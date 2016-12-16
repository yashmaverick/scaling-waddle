#include<stdio.h>
int main()
{
	long long int psp;
	scanf("%lld",&psp);
	while(psp--)
	{
		//char ke;
		//scanf("%c",&ke);
		long long int b,n,m,te[100005]={0};
		int i,j,k;
		scanf("%lld",&b);
		long long int a1[100003];
		for(i=0;i<b;i++)
			scanf("%lld",&a1[i]);
		scanf("%lld",&n);
		long long int a2[100003];
		for(i=0;i<n;i++)
			scanf("%lld",&a2[i]);
		scanf("%lld",&m);
		long long int a3[100003];
		for(i=0;i<m;i++)
			scanf("%lld",&a3[i]);
		long long int count=0;
		int first=0,last=0;
		for(i=n-1;i>=0;i--)
		{first=i;
			last=m-1;
			int mid;
			while(first<=last)
			{	mid=(first+last)/2;
				if(a2[i]<=a3[mid]&&(a2[i]>a3[mid-1]||mid==i))
				{
					te[i]=te[i+1]+m-mid;
					break;
				}
				else if(a2[i]<=a3[mid])
					last=mid-1;
				else
					first=mid+1;
			}
		}
		for(i=0;i<b;i++)
		{first=i;
			last=n-1;
			int mid;
			while(first<=last)
			{       mid=(first+last)/2;
				if(a1[i]<=a2[mid]&&(a1[i]>a2[mid-1]||mid==i))
				{	count+=te[mid];
					break;}
				else if(a1[i]<=a2[mid])
					last=mid-1;
				else
					first=mid+1;
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
