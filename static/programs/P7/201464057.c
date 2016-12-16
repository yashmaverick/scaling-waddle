#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long int a,i;
		scanf("%lld",&a);
		long long int b[1000005];
		for(i=0;i<a;i++)
			scanf("%lld",&b[i]);
		qsort(b, a, sizeof(long long int), cmpfunc);
		long long int count=1,sum=0;
		for(i=0;i<a;i++)
		{
			if(b[i]==b[i+1])
				count++;
			else 
			{
				sum+=count*(count-1)/2;
				count=1;
			}
		}
		sum+=count*(count-1)/2;
		if(sum==2)
			sum=1;
		printf("%lld\n",sum);
	}
	return 0;
}
