#include<stdio.h>
#include<stdlib.h>
int a[1000010];
	int cmfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long int i,c,count;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmfunc);
		c=1;
		count=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
				c++;
			else
			{
				count+=(c*(c-1))/2;
				c=1;
			}
		}
		count+=(c*(c-1))/2;
		printf("%lld\n",count);
	}
	return 0;
}
