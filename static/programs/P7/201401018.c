#include<stdio.h>
#include<stdlib.h>
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
		int n,A[1000001],c=0,i;
		long long int sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		qsort(A, n, sizeof(int), cmpfunc);
//		for(i=0;i<n;i++)
//			printf("%d ",A[i]);
		for(i=0;i<n;i++)
		{
			while(1==1)
			{
				if(A[i]==A[i+1] && i+1<n)
				{
					
					c++;
					i++;
				}
				else
					break;
			}
			if(c>0)
			sum=sum+((long long )(c+1)*(long long)c)/2;
			c=0;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
