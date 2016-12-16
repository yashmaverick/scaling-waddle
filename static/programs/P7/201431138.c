#include<stdio.h>
#include<stdlib.h>
long long cmpfunc(const void *a,const void *b)
{
	return(*(long long int*)a-*(long long int*)b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,i;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		qsort(a,n,sizeof(long long int),cmpfunc);
		long long int l=1,s=0;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				l++;
			else
			{	
				s=s+l*(l-1)/2;
				l=1;
			}
		}
		s=s+l*(l-1)/2;
		printf("%lld\n",s);
		
	}
	return 0;
}
