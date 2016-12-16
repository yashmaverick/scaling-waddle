#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	long long int test,n,i,count,sum;
	scanf("%lld",&test);
	while(test--)
	{
		sum=0;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		qsort(a,n,sizeof(long long int),cmpfunc);
		count=1;
		for(i=0;i<n;i++){
		   
			if(a[i]==a[i+1])
			{
				count++;
			}
			else
			{
				sum+=(count*(count-1))/2;
				count=1;
			}
			   
		}
			printf("%lld\n",sum);
	}
	
//	printf("\n");
	return 0;
}
