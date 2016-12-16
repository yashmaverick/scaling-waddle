#include<stdio.h>
#include<stdlib.h>
int binarysearch(long long int a[],long long int e,long long int l,long long int d)
{
	long long int c=0;
	long long int last=l-1;
	long long int middle;
	while(e<=last)
	{
		middle=(e+last)/2;
		if(d==a[middle])
		{
			c=1;
			break;
		}
		if(d>a[middle])
			e=middle+1;
		else	
			last=middle-1;
	}
	return c;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k,diff;
		scanf("%lld%lld",&n,&k);
		long long int a[1000001],flag=0,i,j;
		char s[10000];
		for(i=0;i<n;i++)
			scanf("%s%lld",s,&a[i]);
		qsort(a, n, sizeof(long long int), cmpfunc);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				long long int sum,diff;
				diff=k-(a[j]+a[i]);
				long long int c;
				c=binarysearch(a,j+1,n,diff);
				if(c==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;			
		}
		if(flag==1)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}