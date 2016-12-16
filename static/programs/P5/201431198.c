#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int binarysearch(long long int d[], long long int first, long long int l, long long int x)
{
	int mid,flag1=0;
	long long int last=l-1;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(x==d[mid])
			{
				flag1=1;
				break;
			}
		if(x>d[mid])
			first=mid+1;
		else
			last=mid-1;
	}
	return flag1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k,a[1000005];
		char s[100000];
		scanf("%lld %lld",&n,&k);
		int i;
		for(i=0;i<n;i++)
			scanf("%s %lld",s,&a[i]);
		qsort(a, n, sizeof(long long int), cmpfunc);
		long long int dif,j;int flag=0,flag2=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				dif=k-(a[i]+a[j]);
				flag = binarysearch(a,j+1,n,dif);
				if(flag==1)
				{
					printf("YES\n");
					flag2=1;
					break;
				}
			}
			if(flag2==1)
				break;
			
		}
		if(flag2==0)
			printf("NO\n");
	}
	return 0;
}