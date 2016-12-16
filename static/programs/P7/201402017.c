#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{       
	return ( *(int*)a - *(int*)b );
}
int main()
{
	long long int s,c,n,i,t;
	int a[1000004];
	scanf("%lld",&t);
	while(t--)
	{
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	//for(i=0;i<n;i++)
	//	printf("%d ",a[i]);
	c=1;s=0;
	for(i=1;i<=n;i++)
	{
		if(a[i-1]==a[i])
		{
			c++;
		}
		else
		{
			
			s=(s+((c*(c-1))/2));
			c=1;
		}
	}
	printf("%lld\n",s);
	}
	return 0;
}
